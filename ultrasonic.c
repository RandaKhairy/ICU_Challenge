/*
 * ultrasonic.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */

#include "ultrasonic.h"

static void (*appFunction)(uint16) = NULL;

void ULTRA_compute_distance(uint16 ultra_time) {
	uint16 distance = ultra_time / 58;
	(*appFunction)(distance);
}

void ULTRA_read(void (*ptr)(uint16)) {
	Nassar = ptr;
	Icu_setCallBack(ULTRA_compute_distance);
	PULSE_start();
}

void ULTRA_init(void) {

	Icu_ConfigType Icu_Config = { F_CPU_8, RISING };
	Icu_init(&Icu_Config);

	PULSE_init();
}

