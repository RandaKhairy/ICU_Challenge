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
#include <stdio.h>

extern void ICU(void);
extern void INT2_Init_Raising_FirstTime(void);

#endif /* ICU_H_ */
