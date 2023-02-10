/*
 * DMA_Defines.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Kunal
 */

#ifndef DMA_DEFINES_H_
#define DMA_DEFINES_H_


#define DMA_Lowe_Power_Mode_Enable	1
#define DMA_Lowe_Power_Mode_Disable	0

#define DMA_Channel_0	0
#define DMA_Channel_1	1
#define DMA_Channel_2	2
#define DMA_Channel_3	3
#define DMA_Channel_4	4
#define DMA_Channel_5	5
#define DMA_Channel_6	6
#define DMA_Channel_7	7

#define DMA_Priority_Very_high	0
#define DMA_Priority_High		1
#define DMA_Priority_Medium		2
#define DMA_Priority_Low		3

#define DMA_Memory_Size_8		0
#define DMA_Memory_Size_16		1
#define DMA_Memory_Size_32		2

#define DMA_Peripheral_Size_8	0
#define DMA_Peripheral_Size_16	1
#define DMA_Peripheral_Size_32	2

#define DMA_Circular_Mode_Enable	1
#define DMA_Circular_Mode_Disable	0

#define DMA_Direction_Peripheral_To_Memory	0
#define DMA_Direction_Memory_To_Peripheral	1
#define DMA_Direction_Memory_To_Memory		2

#define DMA_Flow_Control_DMA			0
#define DMA_Flow_Control_Periheral		1


#define DMA_Interrupt_Full_Transfer_Complete	(1 << 4)
#define DMA_Interrupt_Half_Transfer_Complete	(1 << 3)
#define DMA_Interrupt_Transfer_Error			(1 << 2)
#define DMA_Interrupt_Direct_Mode_Error			(1 << 1)


#endif /* DMA_DEFINES_H_ */
