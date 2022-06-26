/*
 * RingBuffer.h
 *
 *  Created on: May 31, 2022
 *      Author: student
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_

#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void RingBuffer_Init();

uint8_t RingBuffer_IsEmpty();

uint8_t RingBuffer_IsFull();

uint8_t RingBuffer_FreeSpace();

uint8_t RingBuffer_Write(uint8_t* data, size_t dataSize);

uint8_t RingBuffer_Read(uint8_t* data, size_t dataSize);

#endif /* INC_RINGBUFFER_H_ */
