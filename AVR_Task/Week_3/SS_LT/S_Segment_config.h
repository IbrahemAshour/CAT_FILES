/*
 * S_Segment_config.h
 *
 *  Created on: 28 Oct 2023
 *      Author: Alaraby
 */

#ifndef S_SEGMENT_CONFIG_H_
#define S_SEGMENT_CONFIG_H_

#define SS_Num 2
typedef struct{
u8 SEG_APIN	;
u8 SEG_APORT ;

u8 SEG_BPIN  ;
u8 SEG_BPORT ;

u8 SEG_CPIN  ;
u8 SEG_CPORT  ;

u8 SEG_DPIN  ;
u8 SEG_DPORT;

u8 SEG_EPIN  ;
u8 SEG_EPORT ;

u8 SEG_FPIN ;
u8 SEG_FPORT  ;

u8 SEG_GPIN  ;
u8 SEG_GPORT ;

u8 SEG_CMNPIN   ;
u8 SEG_CMNPORT ;

u8 SEG_DOTPIN     ;
u8 SEG_DOTPORT ;

u8 SEG_TYPE	;
}SS_t;


#endif /* S_SEGMENT_CONFIG_H_ */
