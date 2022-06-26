/*
 * workSpace.c
 *
 *  Created on: Jun 16, 2022
 *      Author: student
 */


#include "workSpace.h"
#include "main.h"
extern TIM_HandleTypeDef htim4;

int currBrightness = 10;


void setBrightness(int brightness)
{
	currBrightness = brightness;
	if (currBrightness == 0)
	{
		//stateOff();
		HAL_GPIO_WritePin(Red_LED_GPIO_Port, Red_LED_Pin, GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, 0);
		HAL_TIM_PWM_Stop_IT(&htim4, TIM_CHANNEL_1);
		return;
	}
	HAL_TIM_PWM_Start_IT(&htim4, TIM_CHANNEL_1);

//	__HAL_TIM_SET_COUNTER(&htim4, 0);// clock counter = 0
//	__HAL_TIM_SET_AUTORELOAD(&htim6, 10);// set new clock period

	int dutyCycle = 10*brightness;
	if(dutyCycle > 100)
	{
		dutyCycle = 100;
	}

	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, dutyCycle);
	//HAL_GPIO_WritePin(Red_LED_GPIO_Port, Red_LED_Pin, GPIO_PIN_SET);
}
