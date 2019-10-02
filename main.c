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
#include "Pulse_generator.h"
#include "std_types.h"

void LED_APP(uint16 DISTANCE) {

/*	if (DISTANCE < 20 && DISTANCE > 0) {
		DIO_write(test_led, HIGH);
		LCD_clear();
		LCD_displayString("Obj Detected  ");
		LCD_Write_Integer_Number(DISTANCE);

	} else {
		DIO_write(test_led, LOW);
		LCD_clear();
		LCD_displayString("NO Obj Detected  ");
		LCD_Write_Integer_Number(DISTANCE);
	}*/
	LCD_clear();
	LCD_Write_Integer_Number(DISTANCE);

}

int main(void)

{
	LCD_init();
	LCD_displayString("Hello");
	ULTRA_init();

	DDRB |=(1<<PB5);

	while (1) {
		_delay_ms(100);
		ULTRA_read(LED_APP);

	}
	return 0;
}
