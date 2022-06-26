/*
 * RingBuffer_ADT.h
 *
 *  Created on: 2 Jun 2022
 *      Author: student
 */

#ifndef INC_RINGBUFFER_ADT_H_
#define INC_RINGBUFFER_ADT_H_

#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE 10
#define INIT 0x23
typedef enum
{
	IS_OK,
	IS_FAIL,
}Result;

typedef struct
{
	uint8_t head;
	uint8_t tail;
	uint8_t ringBuf[BUFFER_SIZE];
	uint8_t isInit;
}RingBuffer;



Result RingBuffer_ADT_Init(RingBuffer* ringBuffer);

uint8_t RingBuffer_ADT_IsEmpty(RingBuffer* ringBuffer);

uint8_t RingBuffer_ADT_IsFull(RingBuffer* ringBuffer);

uint8_t RingBuffer_ADT_FreeSpace(RingBuffer* ringBuffer);

Result RingBuffer_ADT_Write(RingBuffer* ringBuffer, uint8_t* data, size_t dataSize);

uint8_t RingBuffer_ADT_Read(RingBuffer* ringBuffer, uint8_t* data, size_t dataSize);


#endif /* INC_RINGBUFFER_ADT_H_ */
