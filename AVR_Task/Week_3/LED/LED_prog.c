/*
 * LED_prog.c
 *
 *  Created on: 27 Oct 2023
 *      Author: Alaraby
 */
#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
#include"LED_config.h"
#include "LED_private.h"

ES_t LED_enuInit(LED_t * Copy_pstrLedConfig)
{
	ES_t Local_enuError=ES_NOK;

	if(Copy_pstrLedConfig==NULL)
	{
		Local_enuError=ES_NULL_POINTER;
	}
	else
	{
		u8 Local_enuIterator=0;
		for(Local_enuIterator=0;Local_enuIterator<LED_Num;Local_enuIterator++)
		{
			Local_enuError = DIO_enuSet_PinDirection(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID,Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID,DIO_u8OUTPUT);
			if(Copy_pstrLedConfig[Local_enuIterator].LED_u8Connection == LED_Sink)
			{
				if(Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_On)
				{
					Local_enuError = DIO_enuSet_PinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID,Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID,DIO_u8LOW);
				}
				else if(Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_Off)
				{
					Local_enuError = DIO_enuSet_PinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID,Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID,DIO_u8HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
		    else if(Copy_pstrLedConfig[Local_enuIterator].LED_u8Connection == LED_Source)
			{
				if(Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_On)
				{
					Local_enuError = DIO_enuSet_PinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID,Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID,DIO_u8HIGH);
				}
				else if(Copy_pstrLedConfig[Local_enuIterator].LED_u8InitState == LED_Off)
				{
					Local_enuError = DIO_enuSet_PinValue(Copy_pstrLedConfig[Local_enuIterator].LED_u8PortID,Copy_pstrLedConfig[Local_enuIterator].LED_u8PinID,DIO_u8LOW);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
		    else
		    {
		    	return ES_OUT_OF_RANGE;
		    }
		}
	}
	return Local_enuError;
}


ES_t LED_enuTurnON(LED_t * Copy_pstrLedID)
{
	ES_t Local_enuError=ES_NOK;
	if(Copy_pstrLedID != NULL)
	{
		if(Copy_pstrLedID -> LED_u8Connection ==LED_Sink)
		{
			Local_enuError=DIO_enuSet_PinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
		}
		else if(Copy_pstrLedID -> LED_u8Connection ==LED_Source)
		{
			Local_enuError=DIO_enuSet_PinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
		}
		else
		{
			Local_enuError=ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_enuError=ES_NULL_POINTER;
	}
	return Local_enuError;
}

ES_t LED_enuTurnOFF(LED_t * Copy_pstrLedID)
{
	ES_t Local_enuError=ES_NOK;
	if(Copy_pstrLedID != NULL)
		{
			if(Copy_pstrLedID -> LED_u8Connection ==LED_Sink)
			{
				Local_enuError=DIO_enuSet_PinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
			}
			else if(Copy_pstrLedID -> LED_u8Connection ==LED_Source)
			{
				Local_enuError=DIO_enuSet_PinValue(Copy_pstrLedID->LED_u8PortID,Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
			}
			else
			{
				Local_enuError=ES_OUT_OF_RANGE;
			}

		}
		else
		{
			Local_enuError=ES_NULL_POINTER;
		}
	return Local_enuError;
}
