/*
 * ultrasonic.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */

#include "ultrasonic.h"

static void (*Nassar)(uint16) = NULL;
/*
void stub(uint16 dis)
{
	DIO_write(test_led, HIGH);
}
*/

void ULTRA_compute_distance(uint16 ultra_time)
{
	uint16 distance = ultra_time/58;
	(*Nassar)(distance);
	//stub(distance);
}

static void ULTRA_sendPulse()
{
	DIO_write(trigger, HIGH);
	//TCNT0 = 0x00;
	TIMER_init();
	//DDRD = 0xff;
	//PORTD = TCNT0;
}

void ULTRA_read(void (*ptr)(uint16))
{
	Nassar = ptr;
	ICU_init();
	ULTRA_sendPulse();
	ICU_capture(ULTRA_compute_distance);
}

