/*
 * ICU_development.c
 *
 * Created: 10/1/2019 9:51:26 AM
 * Author : omar sha3rawy
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "std_types.h"
//#include "randa"

uint16 counts = 0;

void ULTRA_read(void (*ptr)(uint16));

void increment_function(uint16 dis)
{
	if (dis < 400)
	{
	counts++;		
	}
}

//void (*ptr)(uint16) = increment_function;

int main(void)
{
    while (1) 
    {
		ULTRA_read(increment_function);
		_delay_ms(25);
	}
}

/*
uint8 ULTRA_read(ptr)
{
	return (uint8)0 ;
}
*/