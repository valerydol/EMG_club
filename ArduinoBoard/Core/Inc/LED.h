/*
 * LED.h
 *
 *  Created on: Jun 14, 2022
 *      Author: student
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include <stdio.h>
#include <stdbool.h>
#include "main.h"
typedef enum LED_STATE_
{
	STATE_OFF = 0,
	STATE_ON,
	STATE_BLINK
}LED_STATE;


typedef struct _led
{
	LED_STATE state;
	int counter;
	int period;
	GPIO_TypeDef* GPIO_port;
	uint16_t GPIO_Pin;

}LED;

LED_STATE changeStatus(LED* led);


// LED interface

void ledInit(LED* led, GPIO_TypeDef* port, uint16_t pin);

void ledOn(LED* led);

void ledOff(LED* led);

void ledBlink(LED* led, int period);

void ledOnTimerInterrupt(LED* led);

void ledOnPeriodicTask(LED* led);



#endif /* INC_LED_H_ */
