/*
 * DMA.h
 *
 *  Created on: Nov 23, 2022
 *      Author: Kunal
 */

#ifndef DMA_H_
#define DMA_H_

#include "main.h"
#include "DMA_Directives.h"



void DMA_DeInit(DMA_Init_Typedef *DMA_Config);

int DMA_Init(DMA_Init_Typedef *DMA_Config);

int DMA_Trigger(DMA_Init_Typedef *DMA_Config);



#endif /* DMA_H_ */
