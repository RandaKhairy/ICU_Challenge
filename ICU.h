/*
 * ICU.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */

#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

void ICU_init(void);
void ICU_capture(void (*timePtr)(uint16));

#endif /* ICU_H_ */
