/*
 * ICU.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */

#include "ICU.h"

void ICU_init(void)
{

}
void ICU_capture(void (*timePtr)(uint16))
{
	timePtr(30000);

}
