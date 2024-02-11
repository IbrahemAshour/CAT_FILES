/*
 * EXTI_int.h
 *
 *  Created on: 17 Dec 2023
 *      Author: Alaraby
 */

#ifndef MCAL_EXTI_INT_H_
#define MCAL_EXTI_INT_H_

ES_t EXTI_enuInit(EXTI_t *Copy_PStr_StatesArray);
ES_t EXTI_enuChangeSense_Level(u8 Copy_u8Interrupt_ID,u8 Copy_u8SenseLevel);
ES_t EXTI_enuEnable(u8 Copy_u8Interrupt_ID);
ES_t EXTI_enuDisable(u8 Copy_u8Interrupt_ID);
ES_t EXTI_enuCall_Back(volatile void (*Copy_PtoFunAPP)(void *),volatile void *Copy_PvoidParamenter,u8 Copy_u8Interrupt_ID);
/*Interrupt Sense Level */
/*for all interrupt pin*/
#define EXTI_FALLING_EDGE 1
#define EXTI_RISING_EDGE  2

/*for   INT0 & INT1 */
#define EXTI_ONCHANGE     3
#define EXTI_LOW_LEVEL    4
#endif /* MCAL_EXTI_INT_H_ */
