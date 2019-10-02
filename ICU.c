/*
 * ICU.c
 *
 *  Created on: 1 Oct 2019
 *      Author: Mariam Taha
 */

#include "ICU.h"

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL;


void Icu_init(void)
{
	Timer1_overflow();
	External_interrupt_init();
}

void Icu_clearTimerValue(void)
{
	TCNT1 = 0;
}

uint16 Icu_getInputCaptureValue(void)
{
	return TCNT1;
}


void Icu_setEdgeDetectionType(const uint8 a_edgeType)
{
	if(a_edgeType==FALLING)
	{
		MCUCSR &=~(1<<ISC2);
	}
	else if(a_edgeType==RISING)
	{
		MCUCSR |=(1<<ISC2);
	}
}


void Icu_DeInit(void)
{
	GICR &=~(1<<INT2);
}

void Icu_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
	Interrupt_setCallBack(Call_app);
}

void Call_app(void)
{
	(*g_callBackPtr)();
}

