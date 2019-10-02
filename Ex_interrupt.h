/*
 * Ex_interrupt.h
 *
 *  Created on: 1 Oct 2019
 *      Author: Mariam Taha
 */


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_

#include "std_types.h"
#include <avr/interrupt.h>
#include <avr/io.h>

#define Interrupt_Port_direction DDRB
#define Interrupt_PIN PB2

#ifndef SREG
#define SREG  (*(volatile uint8* const)0x005F)
#endif

#define Falling 0
#define Rising 1

void External_interrupt_init(void);
void Interrupt_setCallBack(void(*a_ptr)(void));

#endif /* EXTERNAL_INTERRUPT_H_ */
