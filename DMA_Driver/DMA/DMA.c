/**
 ******************************************************************************
 * @file           : DMA.c
 * @author         : Kunal Salvi
 * @brief          : Main program body
 ******************************************************************************
 */


#include "DMA.h"
#include "DMA_Defines.h"



volatile int stream;
volatile int controller;





void DMA_Init(DMA_Config *self)
{
	/*
	 * Select DMA Controller
	 */

	if(self != NULL)
	{
		if(self->Controller_Typedef == DMA1)
		{
			controller= 1;
			/*
			 *	Low Power mode is selected only when needed otherwise normal DMA is used
			 */
			if(self->Low_Power_Mode == DMA_Lowe_Power_Mode_Enable)
			{
				RCC -> AHB1ENR |= RCC_AHB1LPENR_DMA1LPEN;
			}else
			{
				RCC -> AHB1ENR |= RCC_AHB1ENR_DMA1EN;
			}

			if(self->Stream_Typedef == DMA1_Stream0)
			{
				stream= 0;
			}else if(self->Stream_Typedef == DMA1_Stream1)
			{
				stream= 1;
			}else if(self->Stream_Typedef == DMA1_Stream2)
			{
				stream= 2;
			}else if(self->Stream_Typedef == DMA1_Stream3)
			{
				stream= 3;
			}else if(self->Stream_Typedef == DMA1_Stream4)
			{
				stream= 4;
			}else if(self->Stream_Typedef == DMA1_Stream5)
			{
				stream= 5;
			}else if(self->Stream_Typedef == DMA1_Stream6)
			{
				stream= 6;
			}else if(self->Stream_Typedef == DMA1_Stream7)
			{
				stream= 7;
			}

		}
		if(self->Controller_Typedef == DMA2)
		{
			controller= 2;
			/*
			 *	Low Power mode is selected only when needed otherwise normal DMA is used
			 */
			if(self->Low_Power_Mode == DMA_Lowe_Power_Mode_Enable)
			{
				RCC -> AHB1ENR |= RCC_AHB1LPENR_DMA2LPEN;
			}else
			{
				RCC -> AHB1ENR |= RCC_AHB1ENR_DMA2EN;
			}
			if(self->Stream_Typedef == DMA1_Stream0)
			{
				stream= 0;
			}else if(self->Stream_Typedef == DMA2_Stream1)
			{
				stream= 1;
			}else if(self->Stream_Typedef == DMA2_Stream2)
			{
				stream= 2;
			}else if(self->Stream_Typedef == DMA2_Stream3)
			{
				stream= 3;
			}else if(self->Stream_Typedef == DMA2_Stream4)
			{
				stream= 4;
			}else if(self->Stream_Typedef == DMA2_Stream5)
			{
				stream= 5;
			}else if(self->Stream_Typedef == DMA2_Stream6)
			{
				stream= 6;
			}else if(self->Stream_Typedef == DMA2_Stream7)
			{
				stream = 7;
			}
		}

		self ->	Stream_Typedef -> CR |= (self -> Channel			<< DMA_SxCR_CHSEL_Pos);		//Select Channel
		self ->	Stream_Typedef -> CR |= (self -> Priority_Level		<< DMA_SxCR_PL_Pos);	    //Select Priority Level
		self ->	Stream_Typedef -> CR |= (self -> Memory_Size		<< DMA_SxCR_MSIZE_Pos);	    //Select Memory Size
		self ->	Stream_Typedef -> CR |= (self -> Peripheral_Size	<< DMA_SxCR_PSIZE_Pos);	    //Select Peripheral Size

		if(self	->	Circular_Mode == DMA_Circular_Mode_Enable)
		{
			self ->	Stream_Typedef -> CR |= (self -> Circular_Mode	<<	DMA_SxCR_CIRC_Pos);	    //Enable circular mode
		}
		else
		{
			self -> Stream_Typedef -> CR &= ~(self -> Circular_Mode	<<	DMA_SxCR_CIRC_Pos);	    //Disable circular mode
		}
		self -> Stream_Typedef -> CR |= (self -> Direction << DMA_SxCR_DIR_Pos);				//Direction of Data
		self -> Stream_Typedef -> CR |= (self -> Flow_Control << DMA_SxCR_PFCTRL_Pos);			// Flow Control
	}


}



void DMA_Interrupt_Init(DMA_Config *self)
{
	self -> Stream_Typedef -> CR |=  self->Interrupt;
	if(self -> Interrupt & DMA_Interrupt_Direct_Mode_Error)
	{
		if(stream == 0)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 2);
			self -> Controller_Typedef -> LISR  &= ~(1 << 2);
		}
		if(stream == 1)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 8);
			self -> Controller_Typedef -> LISR  &= ~(1 << 8);
		}
		if(stream == 2)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 18);
			self -> Controller_Typedef -> LISR  &= ~(1 << 18);
		}
		if(stream == 3)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 24);
			self -> Controller_Typedef -> LISR  &= ~(1 << 24);
		}
		if(stream == 4)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 2);
			self -> Controller_Typedef -> HISR  &= ~(1 << 2);
		}
		if(stream == 5)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 8);
			self -> Controller_Typedef -> HISR  &= ~(1 << 8);
		}
		if(stream == 6)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 18);
			self -> Controller_Typedef -> HISR  &= ~(1 << 18);
		}
		if(stream == 7)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 24);
			self -> Controller_Typedef -> HISR  &= ~(1 << 24);
		}
	}

	if(self -> Interrupt & DMA_Interrupt_Transfer_Error)
	{
		if(stream == 0)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 3);
			self -> Controller_Typedef -> LISR  &= ~(1 << 3);
		}
		if(stream == 1)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 9);
			self -> Controller_Typedef -> LISR  &= ~(1 << 9);
		}
		if(stream == 2)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 19);
			self -> Controller_Typedef -> LISR  &= ~(1 << 19);
		}
		if(stream == 3)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 25);
			self -> Controller_Typedef -> LISR  &= ~(1 << 25);
		}
		if(stream == 4)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 3);
			self -> Controller_Typedef -> HISR  &= ~(1 << 3);
		}
		if(stream == 5)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 9);
			self -> Controller_Typedef -> HISR  &= ~(1 << 9);
		}
		if(stream == 6)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 19);
			self -> Controller_Typedef -> HISR  &= ~(1 << 19);
		}
		if(stream == 7)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 25);
			self -> Controller_Typedef -> HISR  &= ~(1 << 25);
		}
	}

	if(self -> Interrupt & DMA_Interrupt_Half_Transfer_Complete)
	{

		if(stream == 0)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 4);
			self -> Controller_Typedef -> LISR  &= ~(1 << 4);
		}
		if(stream == 1)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 10);
			self -> Controller_Typedef -> LISR  &= ~(1 << 10);
		}
		if(stream == 2)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 20);
			self -> Controller_Typedef -> LISR  &= ~(1 << 20);
		}
		if(stream == 3)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 26);
			self -> Controller_Typedef -> LISR  &= ~(1 << 26);
		}
		if(stream == 4)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 4);
			self -> Controller_Typedef -> HISR  &= ~(1 << 4);
		}
		if(stream == 5)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 10);
			self -> Controller_Typedef -> HISR  &= ~(1 << 10);
		}
		if(stream == 6)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 20);
			self -> Controller_Typedef -> HISR  &= ~(1 << 20);
		}
		if(stream == 7)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 26);
			self -> Controller_Typedef -> HISR  &= ~(1 << 26);
		}
	}

	if(self -> Interrupt & DMA_Interrupt_Full_Transfer_Complete)
	{

		if(stream == 0)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 5);
			self -> Controller_Typedef -> LISR  &= ~(1 << 5);
		}
		if(stream == 1)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 11);
			self -> Controller_Typedef -> LISR  &= ~(1 << 11);
		}
		if(stream == 2)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 21);
			self -> Controller_Typedef -> LISR  &= ~(1 << 21);
		}
		if(stream == 3)
		{
			self -> Controller_Typedef -> LIFCR |=  (1 << 27);
			self -> Controller_Typedef -> LISR  &= ~(1 << 27);
		}
		if(stream == 4)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 5);
			self -> Controller_Typedef -> HISR  &= ~(1 << 5);
		}
		if(stream == 5)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 11);
			self -> Controller_Typedef -> HISR  &= ~(1 << 11);
		}
		if(stream == 6)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 21);
			self -> Controller_Typedef -> HISR  &= ~(1 << 21);
		}
		if(stream == 7)
		{
			self -> Controller_Typedef -> HIFCR |=  (1 << 27);
			self -> Controller_Typedef -> HISR  &= ~(1 << 27);
		}
	}
}


void DMA_Trigger(DMA_Config *self)
{
	self -> Stream_Typedef -> CR |= DMA_SxCR_EN;
}



