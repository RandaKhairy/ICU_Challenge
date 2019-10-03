/*
 * Pulse_generator.c
 *
 *  Created on: Oct 2, 2019
 *      Author: PeterKleber
 */

#include "Pulse_generator.h"


void PULSE_init(void)
{
	DDRB |=(1<<PB3);
	SREG |= (1 << 7);
	TCNT0 = 0;
	OCR0 = 35;
	TIMSK |= (1 << OCIE0);
	TCCR0 |= (1<<CS01);
}

void PULSE_start(void)
{
	PORTB |= (1u << PB3);
	PORTB |= (1u << PB5);
	TCCR0 = (1u << FOC0) | (1u << WGM01) | (1u << CS00);
}

void PULSE_stop(void)
{
	TCCR0 &= ~((1u << CS00) | (1u <<CS01) | (1u << CS02));
}

ISR(TIMER0_COMP_vect)
{
	PORTB &= ~(1u << PB3);
	PORTB ^= (1u << PB5);
	PULSE_stop();
}
