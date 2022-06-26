/*
 * myMain.cpp
 *
 *  Created on: Jun 21, 2022
 *      Author: student
 */


#include "myMain.h"
#include "clock.h"
#include "btn.h"
BUTTON btn1;
BUTTON btn2;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim)
{
	incrementClock();
}

// button callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	GPIO_PinState state;
	if(GPIO_Pin == BTN_Pin)
	{
		state = HAL_GPIO_ReadPin(btn1.GPIO_port, btn1.GPIO_Pin);

	}
	if (GPIO_Pin == BTN_2_Pin)
	{
		state = HAL_GPIO_ReadPin(btn2.GPIO_port, btn2.GPIO_Pin);
	}

	if(state == GPIO_PIN_RESET)
	{
		setClockIn();
	}
	else{
		setClockOut();
		uint32_t diff = getDifference();
		int i = 0;
	};


	//	HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
	//	HAL_GPIO_TogglePin(GREEN_GPIO_Port,GREEN_Pin);
	//	HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
}



int myMain ()
{
	initClock();
	Button_init(&btn1,BTN_GPIO_Port , BTN_Pin);
	Button_init(&btn2,BTN_2_GPIO_Port , BTN_2_Pin);

	while(1)
	{

	}


	return 0;
}
