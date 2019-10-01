/*
 * LED_APP.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Mohammed
 */


#include "DIO.h"
#define MAX_DISTANCE 400

sint16 TEST=70;

uint8	test11=1;
//uint8	test22=1;
//uint8	test33=1;
#include <util/delay.h>

uint16 ULTRA_read(void){


		DIO_write(test1,test11);
		test11^=1;
	_delay_ms(  1000 );

	return TEST-- ;

}

/*


uint16 ULTRA_read(APP);


APP(uint16 DISTANCE){

	LED_APP(DISTANCE);

	BUZZER_APP(DISTANCE);

}
*/


func_state LED_APP(uint16 DISTANCE)
{
	func_state state = OK;

	//ULTRA_init();



	//DISTANCE = ULTRA_read();

	if (DISTANCE< MAX_DISTANCE && DISTANCE>0)
	{
		DIO_write(LED0,HIGH);
	}
	else
	{
		DIO_write(LED0,LOW);
	}

return state;
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



int main(void)
{
	DIO_init();
//	uint8 test;


	while (1)
	{
	//LED_APP();
		//BUZZER_APP();

	}



	return (0);
}
