/*
 * btn.cpp
 *
 *  Created on: Jun 23, 2022
 *      Author: student
 */


#include "btn.h"


void Button_init(BUTTON* btn, GPIO_TypeDef* GPIO_port, uint16_t GPIO_Pin)
{
	btn->state = BUTTON_STATE_NONE;
	btn->GPIO_port = GPIO_port;
	btn->GPIO_Pin = GPIO_Pin;
}


BUTTON_STATE checkBtnState(BUTTON* btn)
{
	BUTTON_STATE result = BUTTON_STATE_NONE;
	if((btn->state == BUTTON_STATE_PRESS) && (getDoubleClickTimer() > 0))
	{
		result = BUTTON_STATE_NONE;
	}
	else if (btn->state != BUTTON_STATE_NONE)
	{
		result = btn->state;
		btn->state = BUTTON_STATE_NONE;
	}
	return result;
}
