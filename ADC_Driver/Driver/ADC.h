/*
 * ADC.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Kunal
 */

#ifndef ADC_H_
#define ADC_H_


#include "main.h"
#include "DMA.h"



#define ADC_Resolution_12_Bit 0
#define ADC_Resolution_10_Bit 1
#define ADC_Resolution_8_Bit 2
#define ADC_Resolution_6_Bit 3

#define ADC_Coversion_Mode_Single 0
#define ADC_Coversion_Mode_Continuous 1

typedef struct ADC_Config
{
	ADC_TypeDef *Instance;
	uint8_t resolution;
	bool Conversion_Mode;


}ADC_Config;

void ADC_Init(void);
float Get_IC_Temperature(void);

#endif /* ADC_H_ */
