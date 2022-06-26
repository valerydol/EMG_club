/*
 * workSpace.c
 *
 *  Created on: Jun 16, 2022
 *      Author: student
 */



#include "workSpace.h"
#include "main.h"
extern TIM_HandleTypeDef htim3;

int currBrightness = 10;


void setBrightness(int brightness)
{
	currBrightness = brightness;
	if (currBrightness == 0)
	{
		//HAL_GPIO_WritePin(Red_LED_GPIO_Port, Red_LED_Pin, GPIO_PIN_RESET);
		//__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
		HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);
		return;
	}
	HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);

	int dutyCycle = 10*brightness;
	if(dutyCycle > 100)
	{
		dutyCycle = 100;
	}

	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, dutyCycle);
}
