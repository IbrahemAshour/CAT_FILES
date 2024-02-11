/*
 * ADC_MCAL_int.h
 *
 *  Created on: 8 Feb 2024
 *      Author: Alaraby
 */

#ifndef ADC_MCAL_INT_H_
#define ADC_MCAL_INT_H_

ES_t ADC_enuInit(void);

ES_t ADC_enuEnable(void);

ES_t ADC_enuDisble(void);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuRead_HIGHValue(u8 * Copy_pu8Value);

ES_t ADC_enuRead(u16 * Copy_pu16Value);

ES_t ADC_enuCallBack(void(*Copy_PfunAPPFun)(void*) ,void *Copy_pvidAppParameter);

ES_t ADC_enuSelectChannel(u8 Copy_u8Channel_ID);

ES_t ADC_enuEnableTriggerMode(u8 Copy_u8TriggerSource);

ES_t ADC_enuDisableTriggerMode(void);

ES_t ADC_enuEnableInterruptMode(void);

ES_t ADC_enuDisableInterruptMode(void);

#define ADC_FREE_RUNING              1
#define ADC_ANALOG_COMPARATOR        2
#define ADC_ETERNAL_INTERRUPT_0      3
#define ADC_TIMERT_0_COMPARE_MATCH   4
#define ADC_TIMERT_0_OVERFLOW        5
#define ADC_TIMERT_1_COMPARE_MATCH_B 6
#define ADC_TIMERT_1_OVERFLOW        7
#define ADC_TIMERT_1_CAPTURE_EVENT   8


#endif /* ADC_MCAL_INT_H_ */
