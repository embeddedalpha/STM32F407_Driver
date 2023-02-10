/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kunal Salvi
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>
#include "main.h"
#include "DMA.h"



/**
 * @name			: UART_DMA
 * @brief			: Structure for UART DMA configuration
 * @author			: Kunal Salvi
 * @date			: 2/8/2023
 *
 */

DMA_Config UART_DMA;







int main(void)
{



	UART_DMA.Controller_Typedef = DMA2;
	UART_DMA.Stream_Typedef = DMA2_Stream7;
	UART_DMA.Channel = 4;
	UART_DMA.Circular_Mode = DMA_Circular_Mode_Enable;
	UART_DMA.Data_Size = 15;
	UART_DMA.Direction = DMA_Direction_Memory_To_Peripheral;
	UART_DMA.Flow_Control = DMA_Flow_Control_DMA;
	UART_DMA.Low_Power_Mode = DMA_Lowe_Power_Mode_Disable;
	UART_DMA.Memory_Size = DMA_Memory_Size_8;
	UART_DMA.Peripheral_Size = DMA_Peripheral_Size_8;
	UART_DMA.Priority_Level = DMA_Priority_Very_high;
	UART_DMA.Interrupt = DMA_Interrupt_Full_Transfer_Complete | DMA_Interrupt_Half_Transfer_Complete;
	DMA_Init(&UART_DMA);
	DMA_Interrupt_Init(&UART_DMA);







    /* Loop forever */


	for(;;);
}
