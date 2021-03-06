/*
 * stateMachine.c
 *
 *  Created on: Jun 9, 2022
 *      Author: student
 */

#include "main.h"

#include "FlashLightStateMachine.h"

extern TIM_HandleTypeDef htim6;
int currBrightness = 10;


void stateOff()
{
	HAL_TIM_Base_Stop_IT(&htim6);// stop clock interrupts
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}

void stateOn()
{
	HAL_TIM_Base_Stop_IT(&htim6); // stop clock interrupts
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
}

void stateBlink()
{
	__HAL_TIM_SET_COUNTER(&htim6, 0);// clock counter = 0
	__HAL_TIM_SET_AUTORELOAD(&htim6, 3000);// set new clock period
	HAL_TIM_Base_Start_IT(&htim6);// start interrupts
}

void stateHalfBrightness()
{
	__HAL_TIM_SET_COUNTER(&htim6, 0);// clock counter = 0
	__HAL_TIM_SET_AUTORELOAD(&htim6, 100); // set new clock period
	HAL_TIM_Base_Start_IT(&htim6);// start interrupts
}



void setBrightness(int brightness)
{
	currBrightness = brightness;
	if (currBrightness == 0)
	{
		//stateOff();
		//return;
	}

	__HAL_TIM_SET_COUNTER(&htim6, 0);// clock counter = 0
	__HAL_TIM_SET_AUTORELOAD(&htim6, 10);// set new clock period
	HAL_TIM_Base_Start_IT(&htim6);// start interrupts
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
}


