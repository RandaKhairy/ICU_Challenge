/*
 * ultrasonic.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
#include "DIO.h"
#include "TIMER.h"
#include "ICU.h"

void ULTRA_read(void (*ptr)(uint16));
void ULTRA_init(void);
 void ULTRA_sendPulse();

#endif /* ULTRASONIC_H_ */
