/*
 * RingBuffer_ADT.c
 *
 *  Created on: 2 Jun 2022
 *      Author: student
 */


#include "RingBuffer_ADT.h"



Result RingBuffer_ADT_Init(RingBuffer* ringBuffer)
{
	if(ringBuffer == NULL)
	{
		return IS_FAIL;
	}

	ringBuffer->head = 0;
	ringBuffer->tail = 0;
	ringBuffer -> isInit = INIT;
	memset(ringBuffer->ringBuf, 0, sizeof(ringBuffer->ringBuf));
	return IS_OK;
}


uint8_t RingBuffer_ADT_IsEmpty(RingBuffer* ringBuffer)
{
	if(ringBuffer == NULL)
	{
		return 1;
	}

	if(ringBuffer -> isInit != INIT)
	{
		return 1;
	}

	if(ringBuffer -> head == ringBuffer->tail)
	{
		return 1;
	}
	return 0;
}


uint8_t RingBuffer_ADT_FreeSpace(RingBuffer* ringBuffer)
{
	if(ringBuffer == NULL)
	{
		return 1;
	}

	if(ringBuffer -> isInit != INIT)
	{
		return 1;
	}

	if(ringBuffer ->head == ringBuffer ->tail)
	{
		return BUFFER_SIZE;
	}
	if(ringBuffer ->head > ringBuffer ->tail)
	{
		return (ringBuffer ->head - ringBuffer ->tail);
	}
	return BUFFER_SIZE - (ringBuffer ->tail - ringBuffer ->head);
}


uint8_t RingBuffer_ADT_IsFull(RingBuffer* ringBuffer)
{
	if(ringBuffer == NULL)
	{
		return 1;
	}

	if(ringBuffer -> isInit != INIT)
	{
		return 1;
	}

	if(RingBuffer_ADT_FreeSpace(ringBuffer) == 0)
	{
		return 1;
	}
	return 0;
}

Result RingBuffer_ADT_Write(RingBuffer* ringBuffer, uint8_t* data, size_t dataSize)
{
	if(ringBuffer == NULL)
	{
		return IS_FAIL;
	}

	if(ringBuffer -> isInit != INIT)
	{
		return IS_FAIL;
	}
	// no free space
	if(RingBuffer_ADT_FreeSpace(ringBuffer) < dataSize)
	{
		return IS_FAIL;
	}

	for(int i = 0 ; i < dataSize ; i++)
	{
		ringBuffer->tail = ringBuffer->tail % BUFFER_SIZE;
		ringBuffer->ringBuf[ringBuffer->tail] = data[i];
		ringBuffer->tail++;
	}
	return IS_OK;
}

uint8_t RingBuffer_ADT_Read(RingBuffer* ringBuffer, uint8_t* data, size_t dataSize)
{
	if(ringBuffer == NULL)
	{
		return IS_FAIL;
	}

	if(ringBuffer -> isInit != INIT)
	{
		return IS_FAIL;
	}
	if((BUFFER_SIZE - RingBuffer_ADT_FreeSpace(ringBuffer)) < dataSize)
	{
		return IS_FAIL;
	}
	for(int i = 0; i < dataSize ; i++)
	{
		data[i] = ringBuffer ->ringBuf[ringBuffer ->head];
		ringBuffer-> ringBuf[ringBuffer ->head] = 0;
		ringBuffer-> head++;
		ringBuffer-> head =  ringBuffer ->head % BUFFER_SIZE;
	}
	return dataSize;
}
















