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
#include "motor.h"
#include "PWM.h"



void ULTRA_read(void (*ptr)(uint16));

void obtscales_avoidence(uint16 dis)
{

	if (dis > 20)
	{
		Phase_Correct_PWM(60);
		MOTOR_CarForward();
		LCD_clear();
		LCD_Write_Integer_Number(dis);
	}
	else if (dis >= 18 && dis <= 22)
	{
		MOTOR_CarStop();
		LCD_clear();
		LCD_Write_Integer_Number(dis);
	}
	else
	{
		MOTOR_CarBackward();
		LCD_clear();
		LCD_Write_Integer_Number(dis);
	}
}

//void (*ptr)(uint16) = increment_function;

int main(void)
{
	Phase_Correct_PWM(60);
	LCD_init();
	LCD_displayString("Hello");
	ULTRA_init();

	ULTRA_read(obtscales_avoidence);

	while (1) {
		_delay_ms(1000);
		ULTRA_read(obtscales_avoidence);
	}
	return 0;
}
