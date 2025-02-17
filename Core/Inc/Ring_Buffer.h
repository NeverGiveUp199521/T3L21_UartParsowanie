/*
 * Ring_Buffer.h
 *
 *  Created on: Nov 2, 2020
 *      Author: Pawel
 */
#include "main.h"
#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_

#define RING_BUFFER_SIZE 32

typedef enum
{
	RB_OK = 0,
	RB_ERROR = 1
}RB_Status;

typedef struct
{
	uint8_t Head;
	uint8_t Tail;
	uint8_t Buffer[RING_BUFFER_SIZE];
}RingBuffer;
RB_Status RB_Read(RingBuffer *rb, uint8_t *value);

RB_Status RB_Write(RingBuffer *rb, uint8_t value);


#endif /* INC_RING_BUFFER_H_ */
