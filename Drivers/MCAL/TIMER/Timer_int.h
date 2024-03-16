/*
 * Timer_int.h
 *
 *  Created on: 5 Mar 2024
 *      Author: Alaraby
 */

#ifndef MCAL_TIMER_INT_H_
#define MCAL_TIMER_INT_H_


#define F_CPU_T 1000   /*the frequncy with KHZ*/

typedef enum
{
	Timer_NoPrescaler=1,
	Timer_Prescaler_8=8,
	Timer_Prescaler_64=64,
	Timer_Prescaler_256=256,
	Timer_Prescaler_1024=1024
}Timer_Presacler_t;

typedef enum
{
	Timer0_OVERFLOW_Mode,
	Timer0_PWM_Phase_correct_mode,
	Timer0_CTC_Mode,
	Timer0_PWM_Fast_Mode

}Timer_WaveFormMode_t;

typedef enum
{
	OCR0_DISCONNECTED,
	OCR0_TOGGLE_COMP,
	OCR0_CLEAR_COMP,
	OCR0_SET_COMP,
	PWM_inverted,
	PWM_NONinverted
}Timer_OUTPUT_Action_t;

typedef struct
{
	Timer_WaveFormMode_t Timer0_WAVE_Mode;
	Timer_Presacler_t Timer0_prescaler;
	Timer_OUTPUT_Action_t Timer0_Output_Action;
	unsigned char Timer0_Intial_Value;
	unsigned char Timer0_Compare_Value;

}Timer0_t;

ES_t Timer0_enuInit(Timer0_t *Copy_ptsTimer0);
ES_t Timer0_enuSetSYSDelay(u32 Copy_u32Time);
ES_t Timer0_enuOVF_Interupt_Enable(void);
ES_t Timer0_enuOVF_Interupt_Disable(void);
ES_t Timer0_enuCTC_Interupt_Enable(void);
ES_t Timer0_enuCTC_Interupt_Disable(void);
ES_t Timer0_enuCallBackFunction(void (* Copy_PtFuncCallBack)(void *),void * Copy_pforParamenter);
ES_t Timer0_enuSetOCR0_Value(u8 Copy_u8CompareValue);
ES_t Timer0_enuOutAnalog_Voltage_PWM(f32 Copy_f32Voltage);
#endif
/* MCAL_TIMER_INT_H_ */


