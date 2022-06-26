/*
 * RingBuffer.c
 *
 *  Created on: May 31, 2022
 *      Author: student
 */


#include "RingBuffer.h"


static uint8_t head = 0;
static uint8_t tail = 0;
static uint8_t ringBuffer[BUFFER_SIZE];


void RingBuffer_Init()
{
	head = 0;
	tail = 0;
	memset(ringBuffer, 0, sizeof(ringBuffer));
}

uint8_t RingBuffer_IsEmpty()
{
	if(head == tail)
	{
		return 1;// is empty

	}
	return 0;
}

uint8_t RingBuffer_IsFull()
{
	if(RingBuffer_FreeSpace() == 0)
	{
		return 1; // if Full
	}
	return 0;
}

uint8_t RingBuffer_FreeSpace()
{
	if(head == tail)
	{
		return BUFFER_SIZE;
	}
	if(head > tail)
	{
		return (head - tail);
	}
	return BUFFER_SIZE - (tail - head);
}

uint8_t RingBuffer_Write(uint8_t* data, size_t dataSize)
{
	// no free space
	if(RingBuffer_FreeSpace() < dataSize)
	{
		return 0;
	}
	for(int i = 0 ; i < dataSize ; i++)
	{
		tail = tail % BUFFER_SIZE;
		ringBuffer[tail] = data[i];
		tail++;
	}
	return 1;
}

uint8_t RingBuffer_Read(uint8_t* data, size_t dataSize)
{
	if((BUFFER_SIZE - RingBuffer_FreeSpace()) < dataSize)
	{
		return 0;
	}
	for(int i = 0; i < dataSize ; i++)
	{
		head =  head % BUFFER_SIZE;
		data[i] = ringBuffer[head];
		head++;
	}
	return dataSize;
}
