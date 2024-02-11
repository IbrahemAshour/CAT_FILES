#include "../LIBERARY/stdTypes.h"
#include "../LIBERARY/Error_State.h"
#include"../HAL/LCD_int.h"
#include "APP.h"
#include<util/delay.h>
int pos = 0;
u8 dis=0;
void Backword(void)
{
	dis =0;
	for ( ; pos >=0  ; pos--)
	{
		LCD_voidGotoXY(0 , pos);
		LCD_enuDisplayCharacter(0x6F);
		_delay_ms(15);

		LCD_voidClearDisplay();
		_delay_ms(5);
	}
}
void Forward(void)
{
	dis =0;
	for (; pos <= 15 ; pos++)
	{
		LCD_voidGotoXY(0 , pos);
		LCD_enuDisplayCharacter(0x6F);
		_delay_ms(15);

		LCD_voidClearDisplay();
		_delay_ms(5);
	}

}
