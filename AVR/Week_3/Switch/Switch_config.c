/*
 * Switch_config.c

 *
 *  Created on: 21 Oct 2023
 *      Author: Alaraby
 */
#include"stdTypes.h"
#include"Error_State.h"
#include"DIO_int.h"
#include"Switch_priv.h"
#include"Switch_config.h"




SW_T SW_AStructSwitchStatus[SW_NUM]={
		{DIO_u8PORTA,DIO_u8PIN2,DIO_u8FLOAT},
		{DIO_u8PORTB,DIO_u8PIN5,DIO_u8PULLUP},
		{DIO_u8PORTC,DIO_u8PIN3,DIO_u8PULLUP}


};

