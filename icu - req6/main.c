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

func_state BUZZER_APP(uint16 DISTANCE)
{
	func_state state = OK;

	//ULTRA_init();

	uint8 delay_time=100;

	//sint16 DISTANCE=0;

//	DISTANCE = ULTRA_read();

	if (DISTANCE> 40)
	{
		//DIO_write(BUZZER,HIGH);
		DIO_write(BUZZER,LOW);
	}
	else if (DISTANCE <= 40)
	{
		DIO_write(test2,HIGH);
		DIO_write(BUZZER,HIGH);
		_delay_ms( ( delay_time*(DISTANCE/40) ) );
		DIO_write(BUZZER,LOW);
	}
	else if (DISTANCE<10)
	{
		DIO_write(BUZZER,HIGH);
	}

return state;
}
//void (*ptr)(uint16) = increment_function;

int main(void)
{
	LCD_init();
	LCD_displayString("Hello");
	ULTRA_init();
	ULTRA_read(BUZZER_APP);

	while (1) {
		_delay_ms(1000);
		ULTRA_read(BUZZER_APP);
	}
	return 0;
}
