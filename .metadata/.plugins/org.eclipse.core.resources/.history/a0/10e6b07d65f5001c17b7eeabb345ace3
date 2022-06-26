/*
 * clock.h
 *
 *  Created on: Jun 23, 2022
 *      Author: student
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

#include "main.h"
#define DOUBLI_CLICK_MS 400
struct ClockTimer{

	uint32_t tickCounter;
	uint32_t tickIn;
	uint32_t tickOut;
	uint32_t tickDoubleClickCounter;
};


void initClock();
void incrementClock();
uint32_t getTick();
void setClockIn();
void setClockOut();
uint32_t getClockOut();
uint32_t getClockIn();
void resetTicks();
uint8_t isInvalidClock();
uint32_t getDifference();



#endif /* INC_CLOCK_H_ */
