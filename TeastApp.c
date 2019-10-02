/*
 * TeastApp.c
 *
 *  Created on: 1 Oct 2019
 *      Author: Mariam Taha
 */

#include "ICU.h"
#include "lcd.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;

void App_processing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_timeHigh = Icu_getInputCaptureValue();
		Icu_setEdgeDetectionType(RISING);
	}
	else if(g_edgeCount == 3)
	{
		g_timePeriod = Icu_getInputCaptureValue();
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 4)
	{
		g_timePeriodPlusHigh = Icu_getInputCaptureValue();
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType(RISING);
	}
}

int main(void)
{
	uint32 freq=0;

	DDRA|=(1<<PA0);
	PORTA|=(1<<PA0);

	LCD_init();

	/* Set the Call back function pointer in the ICU driver */
	Icu_setCallBack(App_processing);

	/* Initialize both the LCD and ICU driver */
	Icu_init();

	while(1)
	{
		SREG &=~(1<<7);
		if(g_edgeCount == 4)
		{
			Icu_DeInit(); /* Disable ICU Driver */
			g_edgeCount = 0;
			LCD_displayString("freq= ");
			/* calculate the period */
			freq = 1000000 / (g_timePeriodPlusHigh - g_timeHigh);
			/* display the period on LCD screen */
			LCD_intgerToString(freq);
			LCD_displayString(" HZ");
		}
		SREG |=(1<<7);
	}
}
