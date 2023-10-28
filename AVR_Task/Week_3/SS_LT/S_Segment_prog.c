/*
 * S_Segment_prog.c
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */
#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
#include "S_Segment_config.h"
#include "S_Segment_priv.h"

extern SS_t S_SEGMENT_AstrSegconfig[SS_Num];
ES_t S_Segment_enuInit(SS_t * Copy_pstrSegConfig)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_pstrSegConfig != NULL)
	{
		u8 Local_u8Iter=0;
		u8 Local_u8IterLoop=0;
		u32 Local_u32CheckError;
		for(Local_u8Iter=0;Local_u8Iter<SS_Num;Local_u8Iter++)
		{
			Local_u32CheckError=(DIO_enuSet_PinDirection(Copy_pstrSegConfig [Local_u8Iter].SEG_APORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_APIN , DIO_u8OUTPUT));
			Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_BPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_BPIN, DIO_u8OUTPUT)<<3);
			Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_CPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_CPIN, DIO_u8OUTPUT)<<6);
			Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_DPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_DPIN, DIO_u8OUTPUT)<<9);
			Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_EPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_EPIN, DIO_u8OUTPUT)<<12);
			Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_FPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_FPIN, DIO_u8OUTPUT)<<15);
			Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_GPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_GPIN, DIO_u8OUTPUT)<<18);

			if(Copy_pstrSegConfig[Local_u8Iter].SEG_CMNPORT != NOT_CONNECTED && Copy_pstrSegConfig[Local_u8Iter].SEG_CMNPIN != NOT_CONNECTED )
			{
				Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_CMNPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_CMNPIN , DIO_u8OUTPUT)<<21);
			}
			if(Copy_pstrSegConfig[Local_u8Iter].SEG_DOTPORT != NOT_CONNECTED && Copy_pstrSegConfig[Local_u8Iter].SEG_DOTPIN != NOT_CONNECTED )
			{
				Local_u32CheckError|=(DIO_enuSet_PinDirection(Copy_pstrSegConfig[Local_u8Iter].SEG_DOTPORT ,Copy_pstrSegConfig[Local_u8Iter].SEG_DOTPIN , DIO_u8OUTPUT)<<24);
			}
			for(Local_u8IterLoop=0 ; Local_u8IterLoop < sizeof(Local_u8IterLoop)*8 ; Local_u8IterLoop+=3)
			 {
				 if( ( ( (Local_u32CheckError)>>Local_u8IterLoop) &7 ) !=ES_OK )
				 {
					 return Local_enuErrorState;
				 }
				 else
				 {
					 Local_enuErrorState=ES_OK;
				 }
			 }

		}


	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


ES_t S_Segment_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num)
{
	ES_t Local_enuErrorState=ES_NOK;
	u8 Local_u8Iter=0;
	u32 Local_u32CheckError;
	if(Copy_u8Num <10 && Copy_u8SegID<SS_Num )
	{

		if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_u32CheckError=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APIN,((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin0)&Get_State_Num));
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPIN,((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin1)&Get_State_Num));
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPIN,((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin2)&Get_State_Num));
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPIN,((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin3)&Get_State_Num));
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPIN,((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin4)&Get_State_Num));
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPIN,((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin5)&Get_State_Num));
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPIN,((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin6)&Get_State_Num));
		}
		else if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_ANODE)
		{
			DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APIN,!((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin0)&Get_State_Num));
			DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPIN,!((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin1)&Get_State_Num));
			DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPIN,!((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin2)&Get_State_Num));
			DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPIN,!((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin3)&Get_State_Num));
			DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPIN,!((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin4)&Get_State_Num));
			DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPIN,!((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin5)&Get_State_Num));
			DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPIN,!((SEG_Au8DiaplayNum[Copy_u8Num]>>Pin6)&Get_State_Num));
		}
	}
//	for(Local_u8Iter=0 ; Local_u8Iter < sizeof(Local_u8Iter)*8 ; Local_u8Iter+=3)
//			 {
//				 if( ( ( (Local_u32CheckError)>>Local_u8Iter) &7 ) !=ES_OK )
//				 {
//					 return Local_enuErrorState;
//				 }
//				 else
//				 {
					 Local_enuErrorState=ES_OK;
//				 }
//			 }
	return Local_enuErrorState;
}

ES_t S_Segment_enuEnableCommon(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8SegID<SS_Num)
	{
		if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPIN != NOT_CONNECTED && S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPORT != NOT_CONNECTED )
		{
			if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPIN , DIO_u8LOW);
			}
			else if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPIN , DIO_u8HIGH);
			}
		}
	}
	return Local_enuErrorState;
}

ES_t S_Segment_enuEnableCathod(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8SegID<SS_Num)
	{
		if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPIN != NOT_CONNECTED && S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPORT != NOT_CONNECTED )
		{
			if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPIN , DIO_u8HIGH);
			}
			else if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CMNPIN , DIO_u8LOW);
			}
		}
	}
	return Local_enuErrorState;
}

ES_t S_Segment_enuEnableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8SegID<SS_Num)
		{
		if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN != NOT_CONNECTED && S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT != NOT_CONNECTED )
		{
			if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN , DIO_u8HIGH);
			}
			else if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN , DIO_u8LOW);
			}
		}
	}
	return Local_enuErrorState;

}

ES_t S_Segment_enuDisableDot(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8SegID<SS_Num)
		{
		if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN != NOT_CONNECTED && S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT != NOT_CONNECTED )
		{
			if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_CATHODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN , DIO_u8LOW);
			}
			else if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_ANODE)
			{
				Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN , DIO_u8HIGH);
			}
		}
	}
	return Local_enuErrorState;
}
ES_t S_Segmet_enuClearDisplay(u8 Copy_u8SegID)
{
	ES_t Local_enuErrorState=ES_NOK;

	u8 Local_u8Iter=0;
	u32 Local_u32CheckError;
	if( Copy_u8SegID<SS_Num )
	{

		if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_CATHODE)
		{
			Local_u32CheckError=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APIN, DIO_u8LOW);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPIN,DIO_u8LOW);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPIN,DIO_u8LOW);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPIN,DIO_u8LOW);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPIN,DIO_u8LOW);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPIN,DIO_u8LOW);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPIN,DIO_u8LOW);
			Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN , DIO_u8LOW);
		}
		else if(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_TYPE == COMMON_ANODE)
		{
			Local_u32CheckError=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_APIN, DIO_u8HIGH);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_BPIN,DIO_u8HIGH);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_CPIN,DIO_u8HIGH);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DPIN,DIO_u8HIGH);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_EPIN,DIO_u8HIGH);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_FPIN,DIO_u8HIGH);
			Local_u32CheckError|=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPORT,S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_GPIN,DIO_u8HIGH);
			Local_enuErrorState=DIO_enuSet_PinValue(S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPORT , S_SEGMENT_AstrSegconfig[Copy_u8SegID].SEG_DOTPIN , DIO_u8HIGH);
		}
	}
	for(Local_u8Iter=0 ; Local_u8Iter < sizeof(Local_u8Iter)*8 ; Local_u8Iter+=3)
			 {
				 if( ( ( (Local_u32CheckError)>>Local_u8Iter) &7 ) !=ES_OK )
				 {
					 return Local_enuErrorState;
				 }
				 else
				 {
					 Local_enuErrorState=ES_OK;
				 }
			 }
	return Local_enuErrorState;
}
