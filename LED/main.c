/*
 * main.c
 *
 *  Created on: 27 Oct 2023
 *      Author: Alaraby
 */
#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
#include "LED_config.h"
#include "LED_int.h"
#include "Switch_config.h"
#include "Switch_int.h"
#include <util/delay.h>
extern LED_t LED_AstrLedConfig[LED_Num];
extern SW_T SW_AStructSwitchStatus[SW_NUM];
int main()
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);
	Switch_enuInit(SW_AStructSwitchStatus);
	u8 pinstate;
	while(1)
	{
		Switch_enuGetstatus(&SW_AStructSwitchStatus[1],&pinstate);
		if(pinstate==0)
		{
			LED_enuTurnON(&LED_AstrLedConfig[1]);
		}
		else
		{
			LED_enuTurnOFF(&LED_AstrLedConfig[1]);
		}

	}
}
