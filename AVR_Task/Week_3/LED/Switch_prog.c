/*
 * Switch_prog.c
 *
 *  Created on: 21 Oct 2023
 *      Author: Alaraby
 */
#include"stdTypes.h"
#include"Error_State.h"
#include"DIO_int.h"

#include"Switch_config.h"
#include"Switch_priv.h"



ES_t Switch_enuInit(SW_T *Copy_AstrSwitches)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(NULL==Copy_AstrSwitches)
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	else{
		u8 Local_u8iliterator=0;
		for(Local_u8iliterator=0;Local_u8iliterator<SW_NUM;Local_u8iliterator++)
	{
			Local_enuErrorState=DIO_enuSet_PinDirection(Copy_AstrSwitches[Local_u8iliterator].SW_PORT_ID , Copy_AstrSwitches[Local_u8iliterator].SW_PIN_ID, DIO_u8INPUT);
			Local_enuErrorState=DIO_enuSet_PinValue(Copy_AstrSwitches[Local_u8iliterator].SW_PORT_ID,Copy_AstrSwitches[Local_u8iliterator].SW_PIN_ID,Copy_AstrSwitches[Local_u8iliterator].SW_STATUS);

	}

	}
	return Local_enuErrorState;
}

ES_t Switch_enuGetstatus(SW_T *Copy_AstrSwitches,u8 *copy_pu8SwitchStatus)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_AstrSwitches!=NULL &&copy_pu8SwitchStatus!=NULL )
	{
		 Local_enuErrorState=DIO_enuget_PinValue(Copy_AstrSwitches->SW_PIN_ID,Copy_AstrSwitches->SW_PORT_ID,copy_pu8SwitchStatus);
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
