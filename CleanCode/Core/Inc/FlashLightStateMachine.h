/*
 * FlashLightStateMachine.h
 *
 *  Created on: Jun 9, 2022
 *      Author: student
 */

#ifndef INC_FLASHLIGHTSTATEMACHINE_H_
#define INC_FLASHLIGHTSTATEMACHINE_H_



typedef enum FlashLightState_
{
	STATE_OFF = 0,
	STATE_ON,
	STATE_HALF_BRIGHTNESS,
	STATE_BLINK
}FlashLightState;


FlashLightState changeState();

#endif /* INC_FLASHLIGHTSTATEMACHINE_H_ */
