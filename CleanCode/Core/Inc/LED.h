/*
 * LED.h
 *
 *  Created on: Jun 23, 2022
 *      Author: student
 */

#ifndef INC_LED_H_
#define INC_LED_H_
#include "main.h"
typedef enum LightState_
{
	STATE_LED_OFF = 0,
	STATE_LED_ON
}LED_STATE;


struct LED
{
	LED_STATE state;
	int counter;
	int period;
	GPIO_TypeDef* GPIO_port;
	uint16_t GPIO_Pin;
};

LED_STATE changeStatus(LED* led);



#endif /* INC_LED_H_ */
