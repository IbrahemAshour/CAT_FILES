/*
 * main.c
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */

#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
#include "S_Segment_config.h"
#include "S_Segment_int.h"
#include <util/delay.h>
extern SS_t S_SEGMENT_AstrSegconfig[SS_Num];
int main()
{
	DIO_enuInit();
	S_Segment_enuInit(S_SEGMENT_AstrSegconfig);

	while(1)
	{
		for(u8 i =0 ;i<10; i++)
		{
			S_Segment_enuDisplayNum(0,i);
			S_Segment_enuDisplayNum(1,i);
			_delay_ms(500);
		}
//		for(u8 j =9 ;j>=0; j--)
//		{
//			S_Segment_enuDisplayNum(1,j);
//			_delay_ms(500);
//		}
	}

	return 0;
}
