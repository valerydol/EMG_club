/*
 * staeMachine.h
 *
 *  Created on: Jun 9, 2022
 *      Author: student
 */

#ifndef INC_STATEMACHINE_H_
#define INC_STATEMACHINE_H_


#include "main.h"
#include "FlashLightStateMachine.h"


void stateOff();

void stateOn();

void stateBlink();

void stateHalfBrightness();

void setBrightness(int brightness);

#endif /* INC_STATEMACHINE_H_ */
