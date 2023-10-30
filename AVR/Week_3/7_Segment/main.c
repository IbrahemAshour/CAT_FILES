/*
 * main.c
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */
#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
#include "S_Segment_int.h"
#include "util/delay.h"


int main()
{
	ES_t Check_error;

	DIO_enuInit();
	Check_error=S_Segment_enuInit();
	while(1)
	{
		if(Check_error==ES_OK)
		{
			for(u8 Ilit=0 ; Ilit<10 ; Ilit++)
			{
				S_Segment_enuDisplayNum(Ilit);
				_delay_ms(500);
			}
		}
	}
	return 0;
}

