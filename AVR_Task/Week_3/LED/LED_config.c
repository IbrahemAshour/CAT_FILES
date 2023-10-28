/*
 * LED_config.c
 *
 *  Created on: 27 Oct 2023
 *      Author: Alaraby
 */

#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
#include "LED_config.h"
#include "LED_private.h"

LED_t LED_AstrLedConfig[LED_Num]=
{
		{DIO_u8PORTA,DIO_u8PIN5,LED_Sink , LED_Off},
		{DIO_u8PORTC,DIO_u8PIN1,LED_Source,LED_On},
};
