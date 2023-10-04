/*
 * snake.c
 *
 *  Created on: Oct 2, 2023
 *      Author: Alaraby
 */
#include<util/delay.h>
#include"stdTypes.h"

#define DDRA   *((volatile u8*)0x3A)
#define PORTA  *((volatile u8*)0x3B)
#define PINA   *((volatile u8*)0x39)


int main()
{
	DDRA=0xFF;
	PORTA=0;
	s8 Snake_Counter=0;
	while(1)
	{

		for(Snake_Counter=0;Snake_Counter<=7;Snake_Counter++)
		{
			PORTA |=(1<<Snake_Counter);
			_delay_ms(500);
		}
		for(Snake_Counter=0;Snake_Counter<=7;Snake_Counter++)
		{
			PORTA &=~(1<<Snake_Counter);
			_delay_ms(500);
		}
	}
}
