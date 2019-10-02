/*
 * main.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */

//#include "register_lib.h"
#include "DIO.h"
#include "ultrasonic.h"
#include "LCD.h"
#include "icu.h"

void stub(uint16 dis) {
	LCD_clear();
	LCD_displayString("T high = ");
	LCD_Write_Integer_Number(dis);
	LCD_displayString(" MiliS");
}

void stub1(uint16 dis) {
	DDRC = 0xff;
	PORTC = 0X0f;
}

int main(void)

{
	DIO_init();

	 DDRB |= (1u << PB3);
	 PORTB &= ~(1u << PB3);

	//LCD_init();
	ULTRA_init();
	ULTRA_read(stub1);
	//LCD_displayString("Hello ");

	//Icu_setCallBack(stub);

	DDRB |= (1 << PB4);

	while (1) {



		/*	ULTRA_read(stub);
		 _delay_ms(2000);*/
	}
	return 0;
}
