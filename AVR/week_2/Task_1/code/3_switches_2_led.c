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

#define DDRB   *((volatile u8*)0x37)
#define PORTB  *((volatile u8*)0x38)
#define PINB   *((volatile u8*)0x36)

#define DDRC   *((volatile u8*)0x34)
#define PORTC  *((volatile u8*)0x35)
#define PINC   *((volatile u8*)0x33)

#define DDRD   *((volatile u8*)0x31)
#define PORTD  *((volatile u8*)0x32)
#define PIND   *((volatile u8*)0x30)
int main()
{

	DDRA =0;
	PORTA=0XFF;
	DDRB=0xff;
	PORTB=0;

	u8 Segment[]={0x3F,0x06,0x5B,
				  0x4F,0x66,0x6D,0x7D,
				  0x07,0x7F,0x6F
				 },Ones,Deci,thu,PIN_Value;

	while(1)
	{
		if(((PINA>>0)&1)==0)
		{
			PORTB|=(1<<0);
			PORTB &=~(1<<1);

		}
		else if(((PINA>>1)&1)==0)
		{
			PORTB|=(1<<1);
			PORTB &=~(1<<0);
		}
		else if(((PINA>>2)&1)==0)
		{
			PORTB|=(1<<1);
			PORTB|=(1<<0);
		}


	}
}
