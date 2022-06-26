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
	clockTimer.tickDoubleClickCounter = DOUBLI_CLICK_MS;
}

void incrementClock()
{
	clockTimer.tickCounter++;
	clockTimer.tickDoubleClickCounter--;
}

void resetDoubleClickTimer()
{
	clockTimer.tickDoubleClickCounter = DOUBLI_CLICK_MS;
}

int32_t getDoubleClickTimer()
{
	return clockTimer.tickDoubleClickCounter;
}

uint32_t getClockOut()
{
	return clockTimer.tickOut;
}

uint32_t getClockIn()
{
	return clockTimer.tickIn;
}

uint32_t getTick()
{
	return clockTimer.tickCounter;
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

void resetTicks()
{
	clockTimer.tickIn = 0;
	clockTimer.tickOut = 0;
}

uint8_t isInvalidClock()
{
	return (getDifference() == clockTimer.tickOut);
}

uint32_t getDifference()
{
	uint32_t differenceTime = 0;
	if(clockTimer.tickOut > clockTimer.tickIn)
	{
		differenceTime = clockTimer.tickOut - clockTimer.tickIn;
	}
	return differenceTime;
}
