/*
 * Icu.c
 *
 *  Created on: Oct 1, 2019
 *      Author: PeterKleber
 */
#include "icu.h"

static volatile void (*g_callBackPtr)(uint16) = NULL_PTR;

uint8 edgeCount = 0;
uint16 timeHigh = 0;

void edgeProcessing(void) {
	edgeCount++;

	if (edgeCount == 1) {

		TCNT1H = 0;
		TCNT1L = 0;
		ICR1H = 0;
		ICR1L = 0;

		Icu_setEdgeDetectionType(FALLING);

	} else if (edgeCount == 2) {

		timeHigh = (ICR1L | (ICR1H << 8));
		Icu_setEdgeDetectionType(RISING);
		edgeCount = 0;

		if (g_callBackPtr != NULL_PTR) {
			(*g_callBackPtr)((timeHigh));
		}
	}
}

ISR( TIMER1_CAPT_vect){
	edgeProcessing();

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

	TCCR1B |= (1 << ICES1);

	/* Initial Value for Timer1 */
	TCNT1H = 0;
	TCNT1L = 0;

	/* Initial Value for the input capture register */
	ICR1H = 0;
	ICR1L = 0;

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

	if (a_edgeType == RISING) {
		TCCR1B |= (1 << ICES1);
	} else {
		TCCR1B &= (~(1 << ICES1));
	}
}
