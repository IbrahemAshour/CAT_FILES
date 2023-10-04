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
	DDRC=0xff;
	PORTC=0;
	DDRD=0xff;
	PORTD=0;

	u8 Segment[]={0x3F,0x06,0x5B,
				  0x4F,0x66,0x6D,0x7D,
				  0x07,0x7F,0x6F
				 },Counter=50,ones,Deci;

	while(1)
	{
		if(((PINA>>0)&1)==0)
		{
			Counter++;

			while(((PINA>>0)&1)==0);
		}
		if(((PINA>>1)&1)==0)
		{


            Counter--;

			while(((PINA>>1)&1)==0);
		}
		ones=Counter%10;
		Deci=Counter/10;
		PORTC=Segment[ones];
		PORTD=Segment[Deci];



	}
}
