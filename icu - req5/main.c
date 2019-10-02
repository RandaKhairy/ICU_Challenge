/*
 * ICU_development.c
 *
 * Created: 10/1/2019 9:51:26 AM
 * Author : omar sha3rawy
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "DIO.h"
#include "ultrasonic.h"
#include "LCD.h"
#include "icu.h"
#include "Pulse_generator.h"
#include "std_types.h"

uint16 counts = 0;

void ULTRA_read(void (*ptr)(uint16));

void increment_function(uint16 dis)
{
	if (dis < 400)
	{
	counts++;		
	}
	if (counts == 100)
	{
		counts = 0;
	}
	LCD_clear();
	//LCD_displayString("Objects count =  ");
	LCD_Write_Integer_Number(counts);

}

//void (*ptr)(uint16) = increment_function;

int main(void)
{
	LCD_init();
	LCD_displayString("Hello");
	ULTRA_init();

	DDRB |=(1<<PB5);

	while (1) {
		_delay_ms(1000);
		ULTRA_read(increment_function);
	}
	return 0;
}

/*
uint8 ULTRA_read(ptr)
{
	return (uint8)0 ;
}
*/
