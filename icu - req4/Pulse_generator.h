/*
 * PULSE_generator.h
 *
 *  Created on: Oct 2, 2019
 *      Author: PeterKleber
 */

#ifndef PULSE_GENERATOR_H_
#define PULSE_GENERATOR_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include "std_types.h"


void PULSE_init(void);
void PULSE_start(void);
void PULSE_stop(void);


#endif /* PULSE_GENERATOR_H_ */
