/*
 * Timer_prog.c
 *
 *  Created on: 5 Mar 2024
 *      Author: Alaraby
 */
#include "LIBERARY/stdTypes.h"
#include "LIBERARY/Error_State.h"
#include "Timer_int.h"
#include "Timer_priv.h"



static Timer0_t *Timer0_Gptos = NULL;
static  void (*Timer0_GptfunTimer0_OVF)(void *) = NULL;
static  void *Timer0_GptparameterTimer0_OVF = NULL;

static  void (*Timer0_GptfunTimer0_CTC)(void *) = NULL;
static  void *Timer0_GptparameterTimer0_CTC = NULL;

ES_t Timer0_enuInit(Timer0_t *Copy_ptsTimer0)
{
	Timer0_Gptos=Copy_ptsTimer0;
	ES_t Local_ErrorState =ES_NOK;
	TCCR0 &=~(1<<7);
	switch(Copy_ptsTimer0->Timer0_prescaler)
	{
	case Timer_NoPrescaler:
		TCCR0 |=(1<<0);
		TCCR0 &=~(1<<1);
		TCCR0 &=~(1<<2);
		break;
	case Timer_Prescaler_8:
		TCCR0 &=~(1<<0);
		TCCR0 |=(1<<1);
		TCCR0 &=~(1<<2);
		break;
	case Timer_Prescaler_64:
		TCCR0 |=(1<<0);
		TCCR0 |=(1<<1);
		TCCR0 &=~(1<<2);
		break;
	case Timer_Prescaler_256:
		TCCR0 &=~(1<<0);
		TCCR0 &=~(1<<1);
		TCCR0 |=(1<<2);
		break;
	case Timer_Prescaler_1024:
		TCCR0 |=(1<<0);
		TCCR0 &=~(1<<1);
		TCCR0 |=(1<<2);
		break;
	default:
		Local_ErrorState =ES_OUT_OF_RANGE;
		break;
	}

	switch(Copy_ptsTimer0->Timer0_WAVE_Mode)
	{
	case Timer0_OVERFLOW_Mode:
		TCCR0 &=~(1<<6);
		TCCR0 &=~(1<<3);
		break;
	case Timer0_PWM_Phase_correct_mode:
		TCCR0 |=(1<<6);
		TCCR0 &=~(1<<3);
		break;
	case Timer0_CTC_Mode:
		TCCR0 &=~(1<<6);
		TCCR0 |=(1<<3);
		break;
	case Timer0_PWM_Fast_Mode:
		TCCR0 |=(1<<6);
		TCCR0 |=(1<<3);
		break;
	default :
		Local_ErrorState = ES_OUT_OF_RANGE;
		break;
	}


	/*
	 * set output action
	 * **/
	if(Copy_ptsTimer0->Timer0_WAVE_Mode == Timer0_OVERFLOW_Mode)
	{
		TCCR0 &=~(1<<4);
		TCCR0 &=~(1<<5);
	}
	else
	{
		if(Copy_ptsTimer0->Timer0_Output_Action ==OCR0_DISCONNECTED)
		{
			TCCR0 &=~(1<<4);
			TCCR0 &=~(1<<5);
		}
		else if(Copy_ptsTimer0->Timer0_Output_Action ==OCR0_TOGGLE_COMP && Copy_ptsTimer0->Timer0_WAVE_Mode == Timer0_CTC_Mode)
		{
			TCCR0 |=(1<<4);
			TCCR0 &=~(1<<5);
		}
		else if(Copy_ptsTimer0->Timer0_Output_Action ==OCR0_CLEAR_COMP ||Copy_ptsTimer0->Timer0_Output_Action ==PWM_NONinverted)
		{
			TCCR0 &=~(1<<4);
			TCCR0 |=(1<<5);
		}
		else if(Copy_ptsTimer0->Timer0_Output_Action ==OCR0_SET_COMP ||Copy_ptsTimer0->Timer0_Output_Action ==PWM_inverted)
		{
			TCCR0 |=(1<<4);
			TCCR0 |=(1<<5);
		}

	}
	OCR0=Copy_ptsTimer0->Timer0_Compare_Value;
	TCNT0=Copy_ptsTimer0->Timer0_Intial_Value;

	return Local_ErrorState;
}


ES_t Timer0_enuSetSYSDelay(u32 Copy_u32Time)
{
	ES_t Local_ErrorState =ES_NOK;
	f32 Local_OVFTime=256*((f32)(Timer0_Gptos->Timer0_prescaler)/F_CPU_T);
	f32 Local_NumOVF=Copy_u32Time/(f32)Local_OVFTime;
	if(Local_NumOVF - (u32)Local_NumOVF != 0.0)
	{
		u32 Local_Num_Int_OVF=(u32)Local_NumOVF + 1;
		Local_NumOVF = Local_NumOVF - Local_Num_Int_OVF;
		u8 Local_Preload = 256 - (256 * Local_NumOVF);
		TCNT0 = Local_Preload;
		while(Local_Num_Int_OVF > 0)
		{
			while(((TIFR >> 0 )&1) == 0);
			TIFR |=(1<<0);
			Local_Num_Int_OVF -- ;
		}
	}
	else
	{
		u32 Local_Num_Int_OVF=Local_NumOVF;
		while(Local_Num_Int_OVF > 0)
		{
			while(((TIFR >> 0 )&1) == 0);
			TIFR |=(1<<0);
			Local_Num_Int_OVF -- ;
		}
	}

	return Local_ErrorState;
}


ES_t Timer0_enuOVF_Interupt_Enable(void)
{
	ES_t Local_ErrorState =ES_NOK;
	TIMSK |=(1<<0);
	SREG  |=(1<<7);
	return Local_ErrorState;
}
ES_t Timer0_enuOVF_Interupt_Disable(void)
{
	ES_t Local_ErrorState =ES_NOK;
	TIMSK &=~(1<<0);
	return Local_ErrorState;
}
ES_t Timer0_enuCTC_Interupt_Enable(void)
{
	ES_t Local_ErrorState =ES_NOK;
	TIMSK |=(1<<1);
	SREG  |=(1<<7);
	return Local_ErrorState;
}
ES_t Timer0_enuCTC_Interupt_Disable(void)
{
	ES_t Local_ErrorState =ES_NOK;
	TIMSK &=~(1<<1);
	return Local_ErrorState;
}
ES_t Timer0_enuCallBackFunction(void (* Copy_PtFuncCallBack)(void *),void * Copy_pforParamenter)
{
	ES_t Local_ErrorState =ES_NOK;
	if(Copy_PtFuncCallBack != NULL)
	{
		switch(Timer0_Gptos->Timer0_WAVE_Mode)
		{
		case Timer0_OVERFLOW_Mode:
			Timer0_GptfunTimer0_OVF=Copy_PtFuncCallBack;
			Timer0_GptparameterTimer0_OVF = Copy_pforParamenter;
			Local_ErrorState = ES_OK;
			break;
		case Timer0_CTC_Mode:
			Timer0_GptfunTimer0_CTC = Copy_PtFuncCallBack;
			Timer0_GptparameterTimer0_CTC = Copy_pforParamenter;
			Local_ErrorState = ES_OK;
			break;
		default :
			break;
		}
	}
	else
	{
		Local_ErrorState =ES_NULL_POINTER;
	}
	return Local_ErrorState;
}
ES_t Timer0_enuSetOCR0_Value(u8 Copy_u8CompareValue)
{
	ES_t Local_ErrorState = ES_NOK;
	OCR0 = Copy_u8CompareValue;
	return Local_ErrorState;
}
ES_t Timer0_enuOutAnalog_Voltage_PWM(f32 Copy_f32Voltage)
{
	ES_t Local_ErrorState =ES_NOK;
	if(Copy_f32Voltage >=0.0 && Copy_f32Voltage <= 5.0 )
	{
		f32 Local_f32PWM_Duty;
		u32 Local_u32Time_Cycle_On_OCR;
		if(Timer0_Gptos->Timer0_Output_Action == PWM_NONinverted)
		{
			Local_f32PWM_Duty = (Copy_f32Voltage*Copy_f32Voltage) / 25.0 ;
			Local_u32Time_Cycle_On_OCR = (u32)(Local_f32PWM_Duty * 256);
			OCR0 |= Local_u32Time_Cycle_On_OCR;

		}
		else if(Timer0_Gptos->Timer0_Output_Action == PWM_inverted)
		{
			Local_f32PWM_Duty = (Copy_f32Voltage*Copy_f32Voltage) / 25.0 ;
			Local_u32Time_Cycle_On_OCR = (u32)(256-(Local_f32PWM_Duty * 256));
			OCR0 |= Local_u32Time_Cycle_On_OCR;
		}

	}
	else
	{
		Local_ErrorState = ES_OUT_OF_RANGE ;
	}

	return Local_ErrorState;
}
ISR(INT_TIMER0_OVF)
{
	if (Timer0_GptfunTimer0_OVF != NULL)
	{
		Timer0_GptfunTimer0_OVF(Timer0_GptparameterTimer0_OVF);
	}
}
ISR(INT_TIMER0_COMP)
{
	if (Timer0_GptfunTimer0_CTC != NULL)
	{
		Timer0_GptfunTimer0_CTC(Timer0_GptparameterTimer0_CTC);
	}
}
