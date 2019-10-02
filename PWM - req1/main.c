/*
 * motormotor2.c
 *
 * Created: 10/2/2019 11:51:23 AM
 * Author : omara
 */

#include <avr/io.h>
#include <util/delay.h>
#include "motor.h"
#include "PWM.h"
#include "LCD.h"

int main(void) {
	DIO_init();
	LCD_init();

	while (1) {

		Phase_Correct_PWM(40);
		MOTOR_CarForward();
		LCD_clear();
		LCD_displayString("CAR SPEED 40%");
		_delay_ms(5000);

		Phase_Correct_PWM(80);
		MOTOR_CarForward();
		LCD_clear();
		LCD_displayString("CAR SPEED 80%");
		_delay_ms(5000);

		Phase_Correct_PWM(100);
		MOTOR_CarForward();
		LCD_clear();
		LCD_displayString("CAR SPEED 100%");
		_delay_ms(5000);

		MOTOR_CarStop();
		LCD_clear();
		LCD_displayString("CAR STOP");
		_delay_ms(5000);
		/*

		 Phase_Correct_PWM(80);
		 MOTOR_CarForward();
		 _delay_ms(5000);

		 Phase_Correct_PWM(40);
		 MOTOR_CarForward();
		 _delay_ms(5000);	*/
		/*
		 MOTOR_CarStop();
		 _delay_ms(1000);
		 MOTOR_CarBackward();
		 _delay_ms(3000);
		 */
	}
}

