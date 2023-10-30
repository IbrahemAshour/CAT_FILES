/*
 * S_Segment_int.h
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */

#ifndef S_SEGMENT_INT_H_
#define S_SEGMENT_INT_H_

ES_t S_Segment_enuInit(SS_t * Copy_pstrSegConfig);

ES_t S_Segment_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num);

ES_t S_Segment_enuEnableCommon(u8 Copy_u8SegID);

ES_t S_Segment_enuEnableCathod(u8 Copy_u8SegID);

ES_t S_Segment_enuEnableDot(u8 Copy_u8SegID);

ES_t S_Segment_enuDisableDot(u8 Copy_u8SegID);

ES_t S_Segmet_enuClearDisplay(u8 Copy_u8SegID);
#endif /* S_SEGMENT_INT_H_ */
