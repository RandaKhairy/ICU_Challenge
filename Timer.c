/*
 * Timer.c
 *
 *  Created on: 1 Oct 2019
 *      Author: Mariam Taha
 */


#include "Timer.h"

void Timer1_overflow(void)
{
	TCCR1A=(1<<FOC1A)|(1<<FOC1B);
	TCNT1=0X0000;
	TCCR1B=(1<<CS11);
}
