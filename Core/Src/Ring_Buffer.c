/*
 * Ring_Buffer.c
 *
 *  Created on: Nov 2, 2020
 *      Author: Pawel
 */
#include "Ring_Buffer.h"
RB_Status RB_Read(RingBuffer *rb, uint8_t *value)
{
	if(rb->Head == rb->Tail)return RB_ERROR;
	*value = rb->Buffer[rb->Tail];
	rb->Tail = (rb->Tail + 1 ) % RING_BUFFER_SIZE;
	return RB_OK;
}
RB_Status RB_Write(RingBuffer *rb, uint8_t value)
{
	uint8_t TmpHead = (rb->Head + 1 ) % RING_BUFFER_SIZE;

	if(TmpHead == rb->Tail)return RB_ERROR;

	rb->Buffer[rb->Head] = value;
	rb->Head = TmpHead;
	return RB_OK;
}
