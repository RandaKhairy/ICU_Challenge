/*
 * DIO_configuration.c
 *
 * Created: 9/20/2019 3:42:04 PM
 *  Author: omara
 */ 

#include "DIO_configuration.h"

DIO_cnfig DIO_cnfig_list [NUM_OF_PINS] =
{
		{PORT_D,PIN2,OUTPUT,LOW,NA,INITIALIZED},//MOTOR_DIR_1_A
		{PORT_D,PIN3,OUTPUT,LOW,NA,INITIALIZED},//MOTOR_DIR_1_B
		{PORT_D,PIN4,OUTPUT,HIGH,NA,INITIALIZED},//MOTOR_1_EN

		{PORT_D,PIN6,OUTPUT,LOW,NA,INITIALIZED},//MOTOR_DIR_2_A
		{PORT_D,PIN7,OUTPUT,LOW,NA,INITIALIZED},//MOTOR_DIR_2_B
		{PORT_D,PIN5,OUTPUT,HIGH,NA,INITIALIZED},//MOTOR_2_EN

		
	

};

