/*
 * main.c
 *
 *  Created on: 21 Oct 2023
 *      Author: Alaraby
 */

#include"stdTypes.h"
#include"Error_State.h"
#include"DIO_int.h"
#include"Switch_config.h"
#include"Switch_int.h"


extern  SW_T SW_AStructSwitchStatus[SW_NUM];


int main()
{
	DIO_enuInit();
	Switch_enuInit(SW_AStructSwitchStatus);
	u8 *Local_u8pinstate=NULL;
	Switch_enuGetstatus(&SW_AStructSwitchStatus[1],Local_u8pinstate);
	if(*Local_u8pinstate==0)
	{
		DIO_enuSet_PinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8HIGH);
	}
	else
		{
			DIO_enuSet_PinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8LOW);
		}

}
