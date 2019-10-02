/*
 * ICU.h
 *
 *  Created on: 1 Oct 2019
 *      Author: Mariam Taha
 */

#ifndef ICU_H_
#define ICU_H_

#include "Timer.h"
#include "Ex_interrupt.h"
#include "std_types.h"

#define FALLING 0
#define RISING 1

void Icu_init(void);
void Icu_clearTimerValue(void);
uint16 Icu_getInputCaptureValue(void);
void Icu_setEdgeDetectionType(const uint8 a_edgeType);
void Icu_DeInit(void);
void Icu_setCallBack(void(*a_ptr)(void));
void Call_app(void);


#endif /* ICU_H_ */
