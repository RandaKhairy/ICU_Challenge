/*
 * ICU.h
 *
 *  Created on: Oct 2, 2019
 *      Author: Mohammed
 */

#ifndef ICU_H_
#define ICU_H_

#include <avr/io.h>		/* Include AVR std. library file */
#include <avr/interrupt.h>
#include <util/delay.h>
#include "DIO.h"
//#include "lcd.h"

#include "std_types.h"

extern uint8 EDGE;

typedef enum {
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024
} Icu_Clock;

typedef enum {
	FALLING, RISING
} Icu_EdgeType;

typedef struct {
	Icu_Clock clock;
	Icu_EdgeType edge;
} Icu_ConfigType;


void Icu_setCallBack(void (*a_ptr)(uint16));  /// dummy
void Icu_init(); //// dummy

void Timer2_init_normal_mode(void);

extern void INT2_Init_Raising_FirstTime(void);

extern void ICU(void);

#endif /* ICU_H_ */
