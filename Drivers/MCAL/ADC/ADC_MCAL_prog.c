/*
 * ADC_MCAL_prog.c
 *
 *  Created on: 8 Feb 2024
 *      Author: Alaraby
 */
#include"LIBERARY/stdTypes.h"
#include"LIBERARY/Error_State.h"
#include"ADC_MCAL_config.h"
#include "ADC_MCAL_priv.h"
#include "ADC_MCAL_int.h"
#include "interrupt.h"

static void (*ADC_pFunISR_Fun)(void *)=NULL;
static void *ADC_pISR_Paramenter =NULL;


ES_t ADC_enuInit(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	/*to handle The prescaler to make CLK Frequency in Range 50KHZ to 200KHZ */
#if(ADC_PRES == PRES_2)
	ADCSRA &=~(1<<ADPS_0);
	ADCSRA &=~(1<<ADPS_1);
	ADCSRA &=~(1<<ADPS_2);
#elif(ADC_PRES == PRES_4)
	ADCSRA &=~(1<<ADPS_0);
	ADCSRA |=(1<<ADPS_1);
	ADCSRA &=~(1<<ADPS_2);
#elif(ADC_PRES == PRES_8)
	ADCSRA |=(1<<ADPS_0);
	ADCSRA |=(1<<ADPS_1);
	ADCSRA &=~(1<<ADPS_2);
#elif(ADC_PRES == PRES_16)
	ADCSRA &=~(1<<ADPS_0);
	ADCSRA &=~(1<<ADPS_1);
	ADCSRA |=(1<<ADPS_2);
#elif(ADC_PRES == PRES_32)
	ADCSRA |=(1<<ADPS_0);
	ADCSRA &=~(1<<ADPS_1);
	ADCSRA |=(1<<ADPS_2);
#elif(ADC_PRES == PRES_64)
	ADCSRA &=~(1<<ADPS_0);
	ADCSRA |=(1<<ADPS_1);
	ADCSRA |=(1<<ADPS_2);
#elif(ADC_PRES == PRES_128)
	ADCSRA |=(1<<ADPS_0);
	ADCSRA |=(1<<ADPS_1);
	ADCSRA |=(1<<ADPS_2);
#else
#error "Error !!Out of Prescaler Range "
#endif
	/*-------------------------------------------------------------------------*/

	/* Choice of ADC Voltage Reference */
#if(ADC_VOLT_REF == AVCC_REF)
	ADMUX |=(1<<REFS_0);
	ADMUX &=~(1<<REFS_1);
#elif(ADC_VOLT_REF == AREF_REF)
	ADMUX &=~(1<<REFS_1);
	ADMUX &=~(1<<REFS_0);

#elif(ADC_VOLT_REF == INTERNAL_REF)
	ADMUX |=(1<<REFS_0);
	ADMUX |=(1<<REFS_1);
#else
#error"Error !! out of Voltage Reference Range"
#endif
	/*-------------------------------------------------------------------------*/

	/*To choose the Adjustable */
#if(ADC_ADJ == RIGHT_ADJ)
	ADMUX &=~(1<<ADLAR);
	Local_enuErrorState =ES_OK;
#elif(ADC_ADJ == LEFT_ADJ)
	ADMUX |=(1<<ADLAR);
	Local_enuErrorState =ES_OK;
#else
#error"Error !! out of Adjustable Range"
#endif


	return Local_enuErrorState;
}
ES_t ADC_enuEnable(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	ADCSRA |=(1<<ADEN);
	Local_enuErrorState =ES_OK;

	return Local_enuErrorState;
}
ES_t ADC_enuDisble(void)
{
	ES_t Local_enuErrorState=ES_NOK;

	ADCSRA &=~(1<<ADEN);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuStartConversion(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	ADCSRA |=(1<< ADSC);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuPollingSystem(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	while(((ADCSRA >> ADIF)&1) == 0);
	ADCSRA |=(1<<ADIF);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuRead_HIGHValue(u8 * Copy_pu8Value)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_pu8Value != NULL)
	{
#if(ADC_ADJ == RIGHT_ADJ)
		*Copy_pu8Value = (ADCL>>2);
		*Copy_pu8Value |=(ADCH <<6);
		Local_enuErrorState =ES_OK;
#elif(ADC_ADJ == LEFT_ADJ)
		*Copy_pu8Value = ADCH;
		Local_enuErrorState =ES_OK;
#else
#error "Error !! out of Adjustable Range"
#endif
	}
	else
	{
		Local_enuErrorState =ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
ES_t ADC_enuRead(u16 * Copy_pu16Value)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_pu16Value != NULL)
	{
		*Copy_pu16Value = ADC_DATA;
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState=ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_t ADC_enuCallBack(void(*Copy_PfunAPPFun)(void*) ,void *Copy_pvidAppParameter)
{
	ES_t Local_enuErrorState=ES_NOK;

	if(Copy_PfunAPPFun != NULL)
	{
		ADC_pFunISR_Fun = Copy_PfunAPPFun;
		ADC_pISR_Paramenter =Copy_pvidAppParameter;
		Local_enuErrorState =ES_OK;
	}
	else
	{
		Local_enuErrorState =ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_t ADC_enuSelectChannel(u8 Copy_u8Channel_ID)
{
	ES_t Local_enuErrorState=ES_NOK;
	if(Copy_u8Channel_ID >= 0 && Copy_u8Channel_ID < 32)
	{
		ADMUX &= 0XE0;
		ADMUX |=Copy_u8Channel_ID;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState =ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
ES_t ADC_enuEnableTriggerMode(u8 Copy_u8TriggerSource)
{
	ES_t Local_enuErrorState=ES_NOK;
	ADCSRA &=~(1<<ADATE);
	switch(Copy_u8TriggerSource)
	{
	case FREE_RUNING:
		SFIOR &=~(1<<ADTS_0);
		SFIOR &=~(1<<ADTS_1);
		SFIOR &=~(1<<ADTS_2);
		break;
	case ANALOG_COMPARATOR:
		SFIOR |=(1<<ADTS_0);
		SFIOR &=~(1<<ADTS_1);
		SFIOR &=~(1<<ADTS_2);
		break;
	case ETERNAL_INTERRUPT_0:
		SFIOR &=~(1<<ADTS_0);
		SFIOR |=(1<<ADTS_1);
		SFIOR &=~(1<<ADTS_2);
		break;
	case TIMERT_0_COMPARE_MATCH:
		SFIOR |=(1<<ADTS_0);
		SFIOR |=(1<<ADTS_1);
		SFIOR &=~(1<<ADTS_2);
		break;
	case TIMERT_0_OVERFLOW:
		SFIOR &=~(1<<ADTS_0);
		SFIOR &=~(1<<ADTS_1);
		SFIOR |=(1<<ADTS_2);
		break;
	case TIMERT_1_COMPARE_MATCH_B:
		SFIOR |=(1<<ADTS_0);
		SFIOR &=~(1<<ADTS_1);
		SFIOR |=(1<<ADTS_2);
		break;
	case TIMERT_1_OVERFLOW:
		SFIOR &=~(1<<ADTS_0);
		SFIOR |=(1<<ADTS_1);
		SFIOR |=(1<<ADTS_2);
		break;
	case TIMERT_1_CAPTURE_EVENT:
		SFIOR |=(1<<ADTS_0);
		SFIOR |=(1<<ADTS_1);
		SFIOR |=(1<<ADTS_2);
		break;
	}
	ADCSRA |=(1<<ADATE);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuDisableTriggerMode(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	ADCSRA &=~(1<<ADATE);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}
ES_t ADC_enuEnableInterruptMode(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	ADCSRA |=(1<<ADIE);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}

ES_t ADC_enuDisableInterruptMode(void)
{
	ES_t Local_enuErrorState=ES_NOK;
	ADCSRA &=~(1<<ADIE);
	Local_enuErrorState =ES_OK;
	return Local_enuErrorState;
}
ISR(INT_ADC)
{
	if(ADC_pFunISR_Fun != NULL)
	{
		ADC_pFunISR_Fun(ADC_pISR_Paramenter);
	}

}

