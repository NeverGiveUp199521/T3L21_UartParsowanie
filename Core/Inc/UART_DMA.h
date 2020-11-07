/*
 * UART_DMA.h
 *
 *  Created on: Nov 3, 2020
 *      Author: Pawel
 */

#ifndef INC_UART_DMA_H_
#define INC_UART_DMA_H_

#include "Ring_Buffer.h"
#include "main.h"

#define DMA_RX_BUFFER_SIZE 64
#define DMA_TX_BUFFER_SIZE 64
typedef struct
{
	UART_HandleTypeDef* huart;  // UART handler

	// ODBIÓR
	uint8_t DMA_RX_Buffer[DMA_RX_BUFFER_SIZE];
	RingBuffer UART_RX_Buffer;
	uint8_t UartRxBufferLines; // '\n'
	// NADAWANIE
	uint8_t DMA_TX_Buffer[DMA_TX_BUFFER_SIZE];
	RingBuffer UART_TX_Buffer;
	uint8_t UartTxBufferLines; // '\n'
}UARTDMA_HandlerTypeDef;

void UARTDMA_Init(UARTDMA_HandlerTypeDef *huartdma, UART_HandleTypeDef *huart);
void UARTDMA_UartIrqHandler(UARTDMA_HandlerTypeDef *huartdma);
void UARTDMA_DmaReceiveIrqHandler(UARTDMA_HandlerTypeDef *huartdma);

void UARTDMA_Print(UARTDMA_HandlerTypeDef *huartdma, char *Message); // Printing to UART

void UARTDMA_TransmitEvent(UARTDMA_HandlerTypeDef *huartdma); // Put this in main loop

uint8_t UARTDMA_IsDataReceivedReady(UARTDMA_HandlerTypeDef *huartdma); // Check if something was received
uint8_t UARTDMA_GetLineFromReceiveBuffer(UARTDMA_HandlerTypeDef *huartdma, char *OutBuffer); // Get one line from receive Ring Buffer



#endif /* INC_UART_DMA_H_ */
