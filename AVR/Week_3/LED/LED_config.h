/*
 * LED_config.h
 *
 *  Created on: 27 Oct 2023
 *      Author: Alaraby
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_Num 2
typedef struct
{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;
	u8 LED_u8InitState;
}LED_t;


#endif /* LED_CONFIG_H_ */
