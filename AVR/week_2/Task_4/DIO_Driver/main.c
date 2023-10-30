/*
 * main.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Alaraby
 */

#include <util/delay.h>
#include "stdTypes.h"
#include "Error_State.h"
#include "DIO_int.h"
int main(void)
{
	u8 Segment[]={0x3F,0x06,0x5B,
				  0x4F,0x66,0x6D,0x7D,
				  0x07,0x7F,0x6F
					 },segment_counter=0;
	DIO_enuInit();
	DIO_enuInit();
	while(1)
	{
		if(segment_counter<=8){
		DIO_enuSet_PortValue(DIO_u8PORTC,Segment[segment_counter]);
		_delay_ms(500);
		segment_counter++;
		}
	}
	
	return 0;
}

