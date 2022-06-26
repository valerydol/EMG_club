/*
 * clock.h
 *
 *  Created on: Jun 23, 2022
 *      Author: student
 */

#ifndef INC_CLOCK_H_
#define INC_CLOCK_H_

#include "main.h"

struct ClockTimer{

	uint32_t tickCounter;
	uint32_t tickIn;
	uint32_t tickOut;
};


void initClock();
void incrementClock();

void setClockIn();
void setClockOut();

uint32_t getDifference();



#endif /* INC_CLOCK_H_ */