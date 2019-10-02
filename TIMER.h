/*
 * TIMER.h
 *
 *  Created on: Sep 21, 2019
 *      Author: Randa
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "Timer_config.h"
#include "DIO.h"
#include <avr/interrupt.h>

#define MAX_NUM_OF_TIMERS 3
#define NUMBER_OF_OVERFLOWS 4

extern volatile uint8 TIMER0_Flag_tick;
extern volatile uint8 TIMER1_Flag_tick;
extern volatile uint8 seven_segment_Flag_tick;


uint8 TIMER_init(void);
uint8 TIMER_PWM(uint8 duty_cycle);
void Timer_PWM(uint8 timer, uint8 duty_cycle);
void TIMER_delay_sec(void(*ServiceFuncPtr)(void),uint8 delay);

#endif /* TIMER_H_ */
