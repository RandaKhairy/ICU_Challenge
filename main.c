/*
 * main.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */
#include "ultrasonic.h"

void stub(uint16 dis)
{
	DIO_write(test_led, LOW);
	//PORTD = TCNT0;

	//DDRD = 0xff;
	PORTD = dis;
}

int main(void)

{
	DIO_init();
	ULTRA_read(stub);
	return 0;
}
