/*
 * Timer_priv.h
 *
 *  Created on: 5 Mar 2024
 *      Author: Alaraby
 */

#ifndef MCAL_TIMER_PRIV_H_
#define MCAL_TIMER_PRIV_H_

#define TCCR0   *((volatile u8*)0X53)
#define TCNT0	*((volatile u8*)0X52)
#define OCR0    *((volatile u8*)0X5C)
#define TIMSK	*((volatile u8*)0X59)
#define TIFR	*((volatile u8*)0X58)
#define SREG  	*((volatile u8*)0X5F)

#define ISR(Interrupt)  void Interrupt(void)__attribute__((signal));\
						void Interrupt(void)

#define INT_TIMER0_OVF __vector_11
#define INT_TIMER0_COMP __vector_10

#define INT_TIMER1_OVF __vector_9
#define INT_TIMER1_COMPB __vector_8
#define INT_TIMER1_COMPA __vector_7
#define INT_TIMER1_CAPT __vector_6


#define INT_TIMER2_OVF __vector_4
#define INT_TIMER2_COMP __vector_5
#endif /* MCAL_TIMER_PRIV_H_ */
