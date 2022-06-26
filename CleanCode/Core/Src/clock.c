/*
 * clock.cpp
 *
 *  Created on: Jun 23, 2022
 *      Author: student
 */


#include "clock.h"
static struct ClockTimer clockTimer ;


void initClock()
{
	clockTimer.tickCounter = 0;
	clockTimer.tickIn = 0;
	clockTimer.tickOut = 0;
}

void incrementClock()
{
	clockTimer.tickCounter++;
}

void setClockIn()
{
	clockTimer.tickIn = clockTimer.tickCounter;
	clockTimer.tickOut = 0;
}

void setClockOut()
{
	clockTimer.tickOut = clockTimer.tickCounter;
}

uint32_t getDifference()
{
	uint32_t differenceTime = 0;
	if(clockTimer.tickOut > clockTimer.tickIn)
	{
		differenceTime = clockTimer.tickOut - clockTimer.tickIn;
		clockTimer.tickOut = 0;
		 clockTimer.tickIn = 0;
	}
	return differenceTime;
}

