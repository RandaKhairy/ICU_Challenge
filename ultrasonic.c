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
	(*Nassar)(distance);
	//stub(distance);
}

 void ULTRA_sendPulse() {
	//DIO_write(trigger, HIGH);
	//DDRC = 0xff;
	//PORTC = 0Xff;
	PORTB |= (1u << PB3);
	_delay_ms(1000);
	PORTB &= ~(1u <<PB3);
	//TIMER_init();
	//_delay_ms(10);
	//DIO_write(trigger, LOW);

}

void ULTRA_read(void (*ptr)(uint16)) {
	Nassar = ptr;

	ULTRA_sendPulse();

	Icu_setCallBack(ULTRA_compute_distance);

}

void ULTRA_init(void) {

	Icu_ConfigType Icu_Config = { F_CPU_8, RISING };
	Icu_init(&Icu_Config);


}

