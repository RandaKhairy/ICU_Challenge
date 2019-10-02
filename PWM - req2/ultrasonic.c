/*
 * ultrasonic.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Randa
 */

#include "ultrasonic.h"

static void (*Nassar)(uint16) = NULL;
/*
 void stub(uint16 dis)
 {
 DIO_write(test_led, HIGH);
 }
 */

void ULTRA_compute_distance(uint16 ultra_time) {
	uint16 distance = ultra_time / 58;
	//uint16 distance = ultra_time;
	(*Nassar)(distance);
	//stub(distance);
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

