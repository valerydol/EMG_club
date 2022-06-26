/*
 * myMain.cpp
 *
 *  Created on: Jun 21, 2022
 *      Author: student
 */


#include "myMain.h"
#include "clock.h"
//#include "btn.h"
#include "main.h"

#define LONG_PRESS_MS 600

BUTTON btn1;
BUTTON btn2;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim)
{
	incrementClock();
}

GPIO_PinState lastState;
BUTTON* lastPressedBtn = NULL;
// button callback
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	GPIO_PinState state;
	BUTTON* pressedBtn = ((GPIO_Pin == BTN_Pin) ? &btn1 : &btn2);

	if(GPIO_Pin == BTN_Pin)
	{
		state = HAL_GPIO_ReadPin(btn1.GPIO_port, btn1.GPIO_Pin);
		//state = HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin);

	}
	if (GPIO_Pin == BTN_2_Pin)
	{
		state = HAL_GPIO_ReadPin(btn2.GPIO_port, btn2.GPIO_Pin);
		//state = HAL_GPIO_ReadPin(BTN_2_GPIO_Port, BTN_2_Pin);
	}

	lastState = state;
	if(lastPressedBtn == NULL)
	{
		lastPressedBtn = (BUTTON*)(&pressedBtn);
		pressedBtn->state = BUTTON_STATE_NONE;
		setClockIn();
	}
	else
	{
		if((state == lastState) && (lastPressedBtn == pressedBtn))
		{
			// DO NOTHING
		}
		else
		{
			if(state == GPIO_PIN_RESET)
			{
				pressedBtn->state = BUTTON_STATE_NONE;
				setClockIn();
			}
			else {
					setClockOut();
					if(! isInvalidClock())
					{
						uint32_t diff = getDifference();
						if(diff > LONG_PRESS_MS)
						{
							pressedBtn->state = BUTTON_STATE_LONG_PRESS;
						}
						else
						{
							pressedBtn->state = BUTTON_STATE_PRESS;
						}
						resetTicks();

						printf("deley BTN  %d , %d , %d\n\r\n\r", ((GPIO_Pin == BTN_Pin)? 1 : 2), diff, pressedBtn->state);
					}
			}
		}
	}

	//printf("Click BTN  %d , %s \n\r", ((GPIO_Pin == BTN_Pin)? 1 : 2), ((state == GPIO_PIN_RESET)? "on" : "off") );

	//	HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
	//	HAL_GPIO_TogglePin(GREEN_GPIO_Port,GREEN_Pin);
	//	HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
}



int myMain ()
{
	initClock();
	Button_init(&btn1, BTN_GPIO_Port, BTN_Pin);
	Button_init(&btn2, BTN_2_GPIO_Port, BTN_2_Pin);

	while(1)
	{

	}


	return 0;
}
