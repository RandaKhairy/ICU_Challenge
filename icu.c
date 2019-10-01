/*
 * Icu.c
 *
 *  Created on: Oct 1, 2019
 *      Author: PeterKleber
 */
#include "icu.h"

static volatile void (*g_callBackPtr)(uint16) = NULL_PTR;

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;

void APP_edgeProcessing(void) {
	g_edgeCount++;

	LCD_clearScreen();
	LCD_displayString("g_edgeCount = ");
	LCD_intgerToString(g_edgeCount);

	if (g_edgeCount == 1) {

		TCNT1 = 0;
		ICR1 = 0;

		Icu_setEdgeDetectionType(FALLING);

	} else if (g_edgeCount == 2) {

		g_timeHigh = ICR1;

		Icu_setEdgeDetectionType(RISING);

	} else if (g_edgeCount == 3) {

		g_timePeriod = ICR1;

		Icu_setEdgeDetectionType(FALLING);

	} else if (g_edgeCount == 4) {

		g_timePeriodPlusHigh = ICR1;
		TCNT1 = 0;
		Icu_setEdgeDetectionType(RISING);

		//Icu_DeInit(); /* Disable ICU Driver */
		g_edgeCount = 0;

		if (g_callBackPtr != NULL_PTR) {

			(*g_callBackPtr)((g_timeHigh / 100));
		}
	}
}

ISR(TIMER1_CAPT_vect) {

	APP_edgeProcessing();

}

void Icu_init(const Icu_ConfigType *Config_Ptr) {

	DDRD &= ~(1 << PD6);

	/* Timer1 always operates in Normal Mode */
	TCCR1A = (1 << FOC1A) | (1 << FOC1B);
	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->clock);
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge) << 6);

	/* Initial Value for Timer1 */
	TCNT1 = 0;

	/* Initial Value for the input capture register */
	ICR1 = 0;

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	TIMSK |= (1 << TICIE1);
	/* Enable Global Interrupt I-Bit */
	SREG |= (1 << 7);
}

void Icu_setCallBack(void (*a_ptr)(uint16)) {
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}

void Icu_setEdgeDetectionType(const Icu_EdgeType a_edgeType) {
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & 0xBF) | (a_edgeType << TCCR1B);
}
