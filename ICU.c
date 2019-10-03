/*
 * ICU.c
 *
 *  Created on: Oct 2, 2019
 *      Author: Mohammed
 */
#include "ICU.h"

static volatile uint8 EXINT = 0;
static volatile void (*g_callBackPtr)(uint16) = NULL_PTR;

uint8 EDGE = 0;

void Icu_setCallBack(void (*a_ptr)(uint16)) {
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}

/* External INT2 Interrupt Service Routine */
ISR(INT2_vect) {

	if (EDGE == 0) {
		//DIO_write(testled1,HIGH);
		EXINT = 1;
		ICU();
		//DIO_write(testled1,HIGH);
	} else if (EDGE == 1) {
		EXINT = 1;
		ICU();
		//	DIO_write(testled2,HIGH);
	}
}

void Timer2_init_normal_mode(void) {
	TCNT2 = 0; //timer initial value
	TCCR2 |= (1 << FOC2) | (1 << CS21) | (1 << CS22) | (1 << CS20); //
	//TCCR2 &= ~((1 << CS22) | (1 << CS20));
	//TCCR2 |= ((1 << CS22) | (1 << CS21));

}

static void Timer2_Clear(void) {
	TCNT2 = 0; //timer initial value
}

void INT2_Init_Raising_FirstTime(void) {

	SREG &= ~(1 << 7);      // Disable interrupts by clearing I-bit
	GICR &= ~(1 << INT2);

	DDRB &= (~(1 << PB2));   // Configure INT2/PB2 as input pin
	MCUCSR |= (1 << ISC2);    // Trigger INT2 with the raising edge
	GICR |= (1 << INT2);	// Enable external interrupt pin INT2

	SREG |= (1 << 7);       // Enable interrupts by setting I-bit
}

static void INT2_Init_Raising(void) {
	GICR &= ~(1 << INT2);
	MCUCSR |= (1 << ISC2);    // Trigger INT2 with the raising edge
	GICR |= (1 << INT2);
}

static void INT2_Init_Falling(void) {
	GICR &= ~(1 << INT2);
	MCUCSR &= ~(1 << ISC2);    // Trigger INT2 with the falling edge
	GICR |= (1 << INT2);
}

void Icu_init() {

	INT2_Init_Raising_FirstTime();
	Timer2_init_normal_mode();

}

void ICU(void) {

	//uint8 TIME=0;

	if ((EXINT == 1) && (EDGE == 0)) {
		INT2_Init_Falling();

		TCNT2 = 0; //timer initial value

		EDGE = 1;
		EXINT = 0;
	}

	else if ((EXINT == 1) && (EDGE == 1)) {
		uint8 TIME=TCNT2;

		if (g_callBackPtr != NULL_PTR) {
			(*g_callBackPtr)(TIME*128);  //TCNT2
		}

		INT2_Init_Raising();
		EDGE = 0;
		EXINT = 0;
	}

}
