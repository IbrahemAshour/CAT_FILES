/*
 * Switch_config.h
 *
 *  Created on: 21 Oct 2023
 *      Author: Alaraby
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#define SW_NUM 3
typedef struct
{
	u8 SW_PORT_ID;
	u8 SW_PIN_ID;
	u8 SW_STATUS;
}SW_T;

#endif /* SWITCH_CONFIG_H_ */
