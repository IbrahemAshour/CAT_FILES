/*
 * S_Segment_config.c
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */
#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
#include "S_Segment_config.h"
#include "S_Segment_priv.h"
SS_t S_SEGMENT_AstrSegconfig[SS_Num]=
 {
	   { DIO_u8PORTA,DIO_u8PIN0,
		 DIO_u8PORTA,DIO_u8PIN1,
		 DIO_u8PORTB,DIO_u8PIN0,
		 DIO_u8PORTB,DIO_u8PIN1,
		 DIO_u8PORTC,DIO_u8PIN0,
		 DIO_u8PORTC,DIO_u8PIN1,
		 DIO_u8PORTD,DIO_u8PIN0,
		 NOT_CONNECTED,NOT_CONNECTED,
		 NOT_CONNECTED,NOT_CONNECTED,
		 COMMON_CATHODE,
		 },
	   { DIO_u8PORTA,DIO_u8PIN2,
		 DIO_u8PORTA,DIO_u8PIN3,
		 DIO_u8PORTB,DIO_u8PIN2,
		 DIO_u8PORTB,DIO_u8PIN3,
		 DIO_u8PORTC,DIO_u8PIN2,
		 DIO_u8PORTC,DIO_u8PIN3,
		 DIO_u8PORTD,DIO_u8PIN1,
		 NOT_CONNECTED,NOT_CONNECTED,
		 NOT_CONNECTED,NOT_CONNECTED,
		 COMMON_ANODE,
		 },
 };
