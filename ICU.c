/*
 * ICU.c
 *
 *  Created on: Oct 2, 2019
 *      Author: Mohammed
 */
#include "ICU.h"

static uint8 EDGE=0;
static volatile uint8 EXINT=0;

/* External INT2 Interrupt Service Routine */
ISR(INT2_vect)
{

	if (EDGE==0){
		//DIO_write(testled1,HIGH);
		EXINT=1;
		//DIO_write(testled1,HIGH);
	}
	else if (EDGE==1)
	{
		EXINT=1;
	//	DIO_write(testled2,HIGH);
	}
}


static void Timer2_init_normal_mode(void)
{
	TCNT2 = 0; //timer initial value
	/* Configure the timer control register
	 * 1. Non PWM mode FOC2=1
	 * 2. Normal Mode WGM21=0 & WGM20=0
	 * 3. Normal Mode COM20=0 & COM21=0
	 * 4. no prescaler clock = F_CPU/1024 CS20=1 CS21=1 CS22=1
	 */
	TCCR2 = (1<<FOC2)  | (1<<CS20)| (1<<CS22) | (1<<CS21) ; //
}

void INT2_Init_Raising_FirstTime(void)
{

	SREG   &= ~(1<<7);      // Disable interrupts by clearing I-bit
	DDRB   &= (~(1<<PB2));   // Configure INT2/PB2 as input pin
	GICR   |= (1<<INT2);	// Enable external interrupt pin INT2
	MCUCSR &= ~(1<<ISC2);    // Trigger INT2 with the raising edge
	SREG   |= (1<<7);       // Enable interrupts by setting I-bit
}

static void INT2_Init_Raising(void)
{
//	SREG   &= ~(1<<7);      // Disable interrupts by clearing I-bit
	MCUCSR &= ~(1<<ISC2);    // Trigger INT2 with the raising edge
	//SREG   |= (1<<7);       // Enable interrupts by setting I-bit
}

static void INT2_Init_Falling(void)
{
	//SREG   &= ~(1<<7);      // Disable interrupts by clearing I-bit
	MCUCSR |= (1<<ISC2);    // Trigger INT2 with the falling edge
//	SREG   |= (1<<7);       // Enable interrupts by setting I-bit
}




void ICU(void){

	//uint8 TIME=0;

	if ( (EXINT==1) && (EDGE == 0) )
	{
	INT2_Init_Falling();
	Timer2_init_normal_mode();
	EDGE = 1 ;
	EXINT = 0;
	}
	else if ( (EXINT==1) && (EDGE == 1) )
	{
		uint8 TIME=TCNT2;
		char arr[50];
		//PORTC = TCNT2;
		//LCD_displayString("TCNT= ");
		sprintf(arr,"%d",TIME);
		//LCD_displayString(arr);
	//TIME = TCNT2;
	INT2_Init_Raising();
	EDGE = 0 ;
	EXINT = 0;
	}

}
