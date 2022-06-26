/*
 * FlashLightStateMachine.c
 *
 *  Created on: Jun 9, 2022
 *      Author: student
 */


#include "FlashLightStateMachine.h"

static FlashLightState lightState = STATE_OFF;



FlashLightState changeState()
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

