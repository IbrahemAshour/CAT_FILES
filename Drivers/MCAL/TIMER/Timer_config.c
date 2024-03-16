/*
 * Timer_config.c
 *
 *  Created on: 5 Mar 2024
 *      Author: Alaraby
 */

#ifndef MCAL_TIMER_CONFIG_C_
#define MCAL_TIMER_CONFIG_C_
#include"../LIBERARY/stdTypes.h"
#include"../LIBERARY/Error_State.h"
#include "Timer_int.h"

Timer0_t Timer0_strConfig=
{
	Timer0_OVERFLOW_Mode,
	Timer_Prescaler_1024,
	OCR0_DISCONNECTED,
	0,
};

#endif /* MCAL_TIMER_CONFIG_C_ */
