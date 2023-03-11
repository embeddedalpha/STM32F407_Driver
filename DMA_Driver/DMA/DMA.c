/*
 * DMA.c
 *
 *  Created on: Nov 23, 2022
 *      Author: Kunal
 */


#include "DMA.h"


static void DMA_Flag_Update(DMA_Init_Typedef *DMA_Config)
{
	if(DMA_Config->DMA_Port == DMA1)
	{
		if(DMA_Config -> Stream == DMA1_Stream0)
		{
			switch (DMA_Config->channel)
			{
				case 0: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_0 = 1;
					    break;
				case 1: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_1 = 1;
					    break;
				case 2: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_2 = 1;
					    break;
				case 3: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_3 = 1;
					    break;
				case 4: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_4 = 1;
					    break;
				case 5: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_5 = 1;
					    break;
				case 6: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_6 = 1;
					    break;
				case 7: DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_7 = 1;
					    break;
			}
		}
/********************************************************************************************************/
		if(DMA_Config -> Stream == DMA1_Stream1)
		{
			switch (DMA_Config->channel)
			{
				case 0: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_0 = 1;
					    break;
				case 1: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_1 = 1;
					    break;
				case 2: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_2 = 1;
					    break;
				case 3: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_3 = 1;
					    break;
				case 4: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_4 = 1;
					    break;
				case 5: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_5 = 1;
					    break;
				case 6: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_6 = 1;
					    break;
				case 7: DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_7 = 1;
					    break;
			}
		}
/**********************************************************************************************************/
		if(DMA_Config -> Stream == DMA1_Stream2)
		{
			switch (DMA_Config->channel)
			{
				case 0: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_0 = 1;
					    break;
				case 1: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_1 = 1;
					    break;
				case 2: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_2 = 1;
					    break;
				case 3: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_3 = 1;
					    break;
				case 4: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_4 = 1;
					    break;
				case 5: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_5 = 1;
					    break;
				case 6: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_6 = 1;
					    break;
				case 7: DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_7 = 1;
					    break;
			}
		}
/*********************************************************************************************************/
		if(DMA_Config -> Stream == DMA1_Stream3)
		{
			switch (DMA_Config->channel)
			{
				case 0: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_0 = 1;
					    break;
				case 1: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_1 = 1;
					    break;
				case 2: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_2 = 1;
					    break;
				case 3: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_3 = 1;
					    break;
				case 4: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_4 = 1;
					    break;
				case 5: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_5 = 1;
					    break;
				case 6: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_6 = 1;
					    break;
				case 7: DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_7 = 1;
					    break;
			}
		}
/**********************************************************************************************************/


	}
}


int DMA_Init(DMA_Init_Typedef *DMA_Config)
{
	int ret_value = 0;
	if(DMA_Config->DMA_Port == DMA1)
	{
		RCC -> AHB1ENR |= RCC_AHB1ENR_DMA1EN;
	}
	else if(DMA_Config->DMA_Port == DMA2)
	{
		RCC -> AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	}
	else
	{
		ret_value = -1;
	}

	if( (DMA_Config -> Stream == DMA1_Stream0) || (DMA_Config -> Stream == DMA2_Stream0) ) DMA_Config -> stream_temp = 0;
	if( (DMA_Config -> Stream == DMA1_Stream1) || (DMA_Config -> Stream == DMA2_Stream1) ) DMA_Config -> stream_temp = 1;
	if( (DMA_Config -> Stream == DMA1_Stream2) || (DMA_Config -> Stream == DMA2_Stream2) ) DMA_Config -> stream_temp = 2;
	if( (DMA_Config -> Stream == DMA1_Stream3) || (DMA_Config -> Stream == DMA2_Stream3) ) DMA_Config -> stream_temp = 3;
	if( (DMA_Config -> Stream == DMA1_Stream4) || (DMA_Config -> Stream == DMA2_Stream4) ) DMA_Config -> stream_temp = 4;
	if( (DMA_Config -> Stream == DMA1_Stream5) || (DMA_Config -> Stream == DMA2_Stream5) ) DMA_Config -> stream_temp = 5;
	if( (DMA_Config -> Stream == DMA1_Stream6) || (DMA_Config -> Stream == DMA2_Stream6) ) DMA_Config -> stream_temp = 6;
	if( (DMA_Config -> Stream == DMA1_Stream7) || (DMA_Config -> Stream == DMA2_Stream7) ) DMA_Config -> stream_temp = 7;

	DMA_Config -> Stream->CR &= ~DMA_SxCR_EN; //Disable DMA Stream
	DMA_Config -> Stream->CR |= (DMA_Config->channel) << DMA_SxCR_CHSEL_Pos; //Select Channel

	DMA_Config -> Stream->CR |= DMA_SxCR_MINC; //Enable memory increment mode
	//Disable Interrupt
	DMA_Config -> Stream->CR  &= ~(DMA_SxCR_HTIE | DMA_SxCR_TCIE | DMA_SxCR_TEIE | DMA_SxCR_DMEIE);
	DMA_Config -> Stream->FCR &= ~(DMA_SxFCR_FEIE);
	//Enable Interrupt
	DMA_Config -> Stream->CR  |= (DMA_Config->Half_Transfer_interrupt     << DMA_SxCR_HTIE_Pos);
	DMA_Config -> Stream->CR  |= (DMA_Config->Transfer_Complete_interrupt << DMA_SxCR_TCIE_Pos);
	DMA_Config -> Stream->CR  |= (DMA_Config->Transfer_Error_interrupt    << DMA_SxCR_TEIE_Pos);
	DMA_Config -> Stream->CR  |= (DMA_Config->Direct_Mode_Error_interrupt << DMA_SxCR_DIR_Pos);
	DMA_Config -> Stream->FCR |= (DMA_Config->FIFO_Overrun_Underrun_interrupt << DMA_SxFCR_FEIE_Pos);

	//Priority
	DMA_Config -> Stream->CR &= ~DMA_SxCR_PL;
	DMA_Config -> Stream->CR |=  DMA_Config->priority << DMA_SxCR_PL_Pos;

	//Direction
	DMA_Config -> Stream->CR &= ~DMA_SxCR_DIR;
	DMA_Config -> Stream->CR |=  DMA_Config->direction << DMA_SxCR_DIR_Pos;

	return ret_value;

}



//int DMA_Trigger(DMA_Init_Typedef *DMA_Config)
//{
//	int ret_value = 0;
//	DMA_Config->Stream->M0AR = (uint32_t)(DMA_Config->Desitnation_Address);
//	DMA_Config->Stream->PAR  = (uint32_t)(DMA_Config->Source_Address);
//	DMA_Config->Stream->NDTR = DMA_Config->data_length;
//	DMA_Config->Stream->CR |= DMA_SxCR_EN;
//
//	if(DMA_Config -> stream_temp <= 3)
//	{
//		switch (DMA_Config -> stream_temp)
//		{
//			case 0:
//			{
//				while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF0_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF0;
//			}
//				break;
//			case 1:
//			{
//				while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF1_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF1;
//			}
//				break;
//			case 2:
//			{
//				while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF2_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF2;
//			}
//				break;
//			case 3:
//			{
//				while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF3_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF3;
//			}
//				break;
//		}
//
//	}
//	else
//	{
//		switch (DMA_Config -> stream_temp)
//		{
//			case 4:
//			{
//				while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF4_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF4;
//			}
//				break;
//			case 5:
//			{
//				while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF5_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF5;
//			}
//				break;
//			case 6:
//			{
//				while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF6_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF6;
//			}
//				break;
//			case 7:
//			{
//				while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF7_Msk)) == 0){}
//				DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF7;
//			}
//				break;
//		}
//	}
//
//	return ret_value;
//}

int DMA_Trigger(DMA_Init_Typedef *DMA_Config)
{
	int ret_value = 0;
	DMA_Config->Stream->M0AR = (uint32_t)(DMA_Config->Desitnation_Address);
	DMA_Config->Stream->PAR  = (uint32_t)(DMA_Config->Source_Address);
	DMA_Config->Stream->NDTR = DMA_Config->data_length;
	DMA_Config->Stream->CR |= DMA_SxCR_EN;

	if(DMA_Config -> stream_temp == 0)
	{
		while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF0_Msk)) == 0){}
		DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF0;
	}
	else if(DMA_Config -> stream_temp == 1)
	{
		while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF1_Msk)) == 0){}
		DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF1;
	}
	else if(DMA_Config -> stream_temp == 2)
	{
		while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF2_Msk)) == 0){}
		DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF2;
	}
	else if(DMA_Config -> stream_temp == 3)
	{
		while((DMA_Config -> DMA_Port -> LISR & (DMA_LISR_TCIF3_Msk)) == 0){}
		DMA_Config -> DMA_Port -> LIFCR |= DMA_LIFCR_CTCIF3;
	}
	else if(DMA_Config -> stream_temp == 4)
	{
		while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF4_Msk)) == 0){}
		DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF4;
	}
	else if(DMA_Config -> stream_temp == 5)
	{
		while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF5_Msk)) == 0){}
		DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF5;
	}
	else if(DMA_Config -> stream_temp == 6)
	{
		while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF6_Msk)) == 0){}
		DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF6;
	}
	else if(DMA_Config -> stream_temp == 7)
	{
		while((DMA_Config -> DMA_Port -> HISR & (DMA_HISR_TCIF7_Msk)) == 0){}
		DMA_Config -> DMA_Port -> HIFCR |= DMA_HIFCR_CTCIF7;
	}

	return ret_value;
}


void DMA_DeInit(DMA_Init_Typedef *DMA_Config)
{
	RCC -> AHB1ENR &= ~(RCC_AHB1ENR_DMA1EN | RCC_AHB1ENR_DMA2EN);

	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_0_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_1_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_2_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_3_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_4_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_5_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_6_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_1_Flag->Stream_7_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_0_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_1_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_2_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_3_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_4_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_5_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_6_Flag->Channel_7 = vacant;

	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_0 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_1 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_2 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_3 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_4 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_5 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_6 = vacant;
	DMA_Config->Flags->DMA_2_Flag->Stream_7_Flag->Channel_7 = vacant;
}


