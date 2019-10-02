/*
 * Ex_interrupt.c
 *
 *  Created on: 1 Oct 2019
 *      Author: Mariam Taha
 */

#include "Ex_interrupt.h"


static volatile void (*Interrupt_callBackPtr)(void) = NULL;

void External_interrupt_init(void)
{
	SREG &=~(1<<7);
	Interrupt_Port_direction &=(~(1<<Interrupt_PIN));
	MCUCSR |=(1<<ISC2);
	GICR |=(1<<INT2);
	SREG |=(1<<7);

}

void Interrupt_setCallBack(void(*I_ptr)(void))
{
	Interrupt_callBackPtr= I_ptr;
}

ISR(INT2_vect)
{
	PORTA &=~(1<<PA0);

	(*Interrupt_callBackPtr)();
}
