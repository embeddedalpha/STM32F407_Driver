/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kunal Salvi
 * @brief          : Main program body
 ******************************************************************************
 */

#ifndef DMA_H_
#define DMA_H_

#include "main.h"
#include "DMA_Defines.h"




/*
 * @name		:	DMA_Config
 * @brief		:	Structure for DMA Configuration
 * @param 		:
 * 		Controller_Typedef	:	Pass the controller to be used. Possible values are
 * 								Valid Values:
 * 											DMA1
 * 											DMA2
 *		Stream_Typedef		:	Pass the stream to be used.
 *								Valid values:
 *											DMA_Stream_0
 *											DMA_Stream_1
 *											DMA_Stream_2
 *											DMA_Stream_3
 *											DMA_Stream_4
 *											DMA_Stream_5
 *											DMA_Stream_6
 *											DMA_Stream_7
 *		Channels			:	Pass the channels to be used.
 *								Valid values:
 *											DMA_Channel_0
 *											DMA_Channel_1
 *											DMA_Channel_2
 *											DMA_Channel_3
 *											DMA_Channel_4
 *											DMA_Channel_5
 *											DMA_Channel_6
 *											DMA_Channel_7
 *		Priority_Level		:	Pass the Priority Level.
 *								Valid values:
 *											DMA_Priority_Very_high
 *											DMA_Priority_High
 *											DMA_Priority_Medium
 *											DMA_Priority_Low
 *		Memory_Size			:	Pass the Size of Memory.
 *								Valid values:
 *											DMA_Memory_Size_8
 *											DMA_Memory_Size_16
 *											DMA_Memory_Size_32
 *		Peripheral_Size		:	Pass the Size of Peripheral.
 *								Valid values:
 *											DMA_Peripheral_Size_8
 *											DMA_Peripheral_Size_16
 *											DMA_Peripheral_Size_32
 *		Data_Size			:	Pass the Size of Data to be processed.
 *								Valid values:
 *											1 to	65535
 *		Circular_Mode		:	Enable or Disable Circular Mode.
 *								Valid values:
 *											DMA_Circular_Mode_Enable
 *											DMA_Circular_Mode_Disable
 *		Direction			:	Pass the direction of data transfer.
 *								Valid values:
 *											DMA_Direction_Peripheral_To_Memory
 *											DMA_Direction_Memory_To_Peripheral
 *											DMA_Direction_Memory_To_Memory
 *		Flow_Control		:	Select Flow Control
 *								Valid values:
 *											DMA_Flow_Control_DMA
 *											DMA_Flow_Control_Periheral
 *		Interrupt			:	Select the interrupt to be enabled.
 *								Valid values:
 *											DMA_Interrupt_Full_Transfer_Complete
 *											DMA_Interrupt_Half_Transfer_Complete
 *											DMA_Interrupt_Transfer_Error
 *											DMA_Interrupt_Direct_Mode_Error
 *
 */


typedef struct DMA_Config
{
	DMA_TypeDef 		*Controller_Typedef;
	bool				Low_Power_Mode;
	DMA_Stream_TypeDef	*Stream_Typedef;
	uint8_t				Channel;
	uint8_t				Priority_Level;
	uint8_t				Memory_Size;
	uint8_t				Peripheral_Size;
	uint16_t			Data_Size;
	bool				Circular_Mode;
	uint8_t				Direction;
	bool 				Flow_Control;
	uint8_t				Interrupt;

}DMA_Config;


/*
 * @name		:	DMA_Init
 * @brief		:	Sets up DMA.
 * @param 		:	DMA_Config
 */
void DMA_Init(DMA_Config *self);

/*
 * @name		:	DMA_Interrupt_Init
 * @brief		:	Sets up Interrupts for DMA.
 * @param 		:	DMA_Config
 */
void DMA_Interrupt_Init(DMA_Config *self);

/*
 * @name		:	DMA_Trigger
 * @brief		:	Triggers DMA stream
 * @param 		:	DMA_Config
 */
void DMA_Trigger(DMA_Config *self);



#endif /* DMA_H_ */
