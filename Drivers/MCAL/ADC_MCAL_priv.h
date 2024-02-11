/*
 * ADC_MCAL_priv.h
 *
 *  Created on: 8 Feb 2024
 *      Author: Alaraby
 */

#ifndef ADC_MCAL_PRIV_H_
#define ADC_MCAL_PRIV_H_

#define PRES_2       1
#define PRES_4       2
#define PRES_8       3
#define PRES_16      4
#define PRES_32      5
#define PRES_64      6
#define PRES_128     7

#define AVCC_REF     0
#define AREF_REF     1
#define INTERNAL_REF 2

#define RIGHT_ADJ    2
#define LEFT_ADJ     5

#define ADMUX     *((volatile u8*)0X27 )
#define ADCSRA    *((volatile u8*)0X26 )
#define SFIOR	  *((volatile u8*)0X50 )
#define ADCH      *((volatile u8*)0X25 )
#define ADCL      *((volatile u8*)0X24 )
#define ADC_DATA  *((volatile u16*)0X24)

/*-------------ADCSAR Register ---------------------*/
#define ADEN   7   /*ADC Enable by writing it 1  -- disable by 0*/
#define ADSC   6   /*ADC start conversion in single mode by  1 -- and continuous mode by  0 */
#define ADATE  5   /*ADC auto trigger by put it by 1 -- turn off by 0*/
#define ADIF   4   /* ADC Interrupt flag */
#define ADIE   3   /* ADC Interrupt enable after conversion done by setting it by 1 and I_bit in SREG is enable*/
#define ADPS_2 2   /* prescaler bits to manage the CLK for ADC*/
#define ADPS_1 1
#define ADPS_0 0

/*-------------ADMUX Register Pin ---------------------*/
#define REFS_1 7
#define REFS_0 6
#define ADLAR  5
#define MUX_0  0  /*from 0 -> 7 single ended input otherwise for  differential input */
#define MUX_1  1
#define MUX_2  2
#define MUX_3  3
#define MUX_4  4

/*---------------SFIOR Register Pin-------------------*/
#define  ADTS_0 5
#define  ADTS_1 6
#define  ADTS_2 7
/*----------Auto Trigger Options----------------------*/
#define FREE_RUNING              1
#define ANALOG_COMPARATOR        2
#define ETERNAL_INTERRUPT_0      3
#define TIMERT_0_COMPARE_MATCH   4
#define TIMERT_0_OVERFLOW        5
#define TIMERT_1_COMPARE_MATCH_B 6
#define TIMERT_1_OVERFLOW        7
#define TIMERT_1_CAPTURE_EVENT   8


#endif /* ADC_MCAL_PRIV_H_ */
