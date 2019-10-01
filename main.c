/*
 * ICU_development.c
 *
 * Created: 10/1/2019 9:51:26 AM
 * Author : omara
 */ 

#include <avr/io.h>
#include "std_types.h"
//#include "randa"
uint8 ULTRA_read();


int main(void)
{
	uint8 counts = 0;
    /* Replace with your application code */
    while (1) 
    {
		if(ULTRA_read())
		{
			counts++;
		}
	}
}

uint8 ULTRA_read()
{
	return (uint8)0 ;
}
