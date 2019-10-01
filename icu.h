/*
 * Icu.h
 *
 *  Created on: Oct 1, 2019
 *      Author: PeterKleber
 */
#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}Icu_Clock;

typedef enum
{
	FALLING,RISING
}Icu_EdgeType;

typedef struct
{
	Icu_Clock clock;
	Icu_EdgeType edge;
}Icu_ConfigType;


void Icu_init(const Icu_ConfigType * Config_Ptr);

void Icu_setCallBack(void(*a_ptr)(uint16));

void Icu_setEdgeDetectionType(const Icu_EdgeType edgeType);

#endif /* ICU_H_ */
