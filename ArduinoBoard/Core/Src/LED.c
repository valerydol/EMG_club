/*
 * LED.c
 *
 *  Created on: Jun 14, 2022
 *      Author: student
 */

#include "LED.h"

extern UART_HandleTypeDef htim2;
extern  TIM_HandleTypeDef htim4;

#define PERIOD_SHORT 300
#define PERIOD_LONG 700
LED_STATE changeStatus(LED* led)
{
	switch(led->state)
	{
	case STATE_OFF:
		led->state = STATE_ON;
		break;
	case STATE_ON:
		led->state = STATE_BLINK;
		break;
	case STATE_BLINK:
		led->state = STATE_OFF;
		break;
	default:
		led->state = STATE_OFF;
		break;
	}
	return led->state;
}

void ledInit(LED* led, GPIO_TypeDef* port, uint16_t pin)
{
	led->state = STATE_OFF;
	led->GPIO_port = port;
	led->GPIO_Pin = pin;
	led->counter = 0;
	led->period = 0;
}

void ledOn(LED* led)
{
	led->state = STATE_ON;
	led->counter = 0;
	HAL_TIM_Base_Stop_IT(&htim4);// stop clock interrupts
	HAL_GPIO_WritePin(led->GPIO_port, led->GPIO_Pin, GPIO_PIN_SET);
}

void ledOff(LED* led)
{
	led->state = STATE_OFF;
	led->counter = 0;
	HAL_TIM_Base_Stop_IT(&htim4);// stop clock interrupts
	HAL_GPIO_WritePin(led->GPIO_port, led->GPIO_Pin, GPIO_PIN_RESET);
}

void ledBlink(LED* led, int period)
{
	led->state = STATE_BLINK;
	led->counter = 0;
	led->period = period;
	__HAL_TIM_SET_COUNTER(&htim4, 0);// clock counter = 0
	__HAL_TIM_SET_AUTORELOAD(&htim4, 100);// set new clock period
	HAL_TIM_Base_Start_IT(&htim4);// start interrupts
}

void ledOnTimerInterrupt(LED* led)
{
	led->counter +=100;
}

void ledOnPeriodicTask(LED* led)
{
	switch(led->state)
	{
	case STATE_ON:
		ledOn(led);
		break;
	case STATE_OFF:
		ledOff(led);
		break;
	case STATE_BLINK:
		if(led->counter >= led->period)
		{
			HAL_GPIO_TogglePin(led->GPIO_port, led->GPIO_Pin);
			led->counter = 0;
		}
		break;
	default:
		ledOff(led);
		break;
	}
}

