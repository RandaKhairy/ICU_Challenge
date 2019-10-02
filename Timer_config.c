/*
 * Timer_config.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Randa
 */

#include "Timer_config.h"

TIMER_cnfg_t timers[num_of_timers] = {
		{ OUTCOMP, Timer0, ON, Prescaler_8,
		IN_CLK, NA, NA, NA, NA, Wave_generation, NA, WG_TOGGLE_Pin, NA, NA, 0x00,
		250, NA, NA, INITIALISED }
};

