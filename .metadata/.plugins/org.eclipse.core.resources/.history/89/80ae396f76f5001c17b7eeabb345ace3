/*
 * LED.cpp
 *
 *  Created on: Jun 23, 2022
 *      Author: student
 */

#include "LED.h"



LED changeState()
{
	switch(lightState)
	{
	case STATE_OFF:
		lightState = STATE_ON;
		break;
	case STATE_ON:
		lightState = STATE_HALF_BRIGHTNESS;
		break;
	case STATE_HALF_BRIGHTNESS:
		lightState = STATE_BLINK;
		break;
	case STATE_BLINK:
		lightState = STATE_OFF;
		break;
	default:
		lightState = STATE_OFF;
		break;
	}
	return lightState;
}


