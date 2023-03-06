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

#define ADC_Sampling_Frequency_2000000	0
#define ADC_Sampling_Frequency_1111111	1
#define ADC_Sampling_Frequency_750000	2
#define ADC_Sampling_Frequency_441176	3
#define ADC_Sampling_Frequency_321500	4
#define ADC_Sampling_Frequency_241935	5
#define ADC_Sampling_Frequency_192307	6
#define ADC_Sampling_Frequency_60975	7

#define ADC_Pin_Type_Normal 	0
#define ADC_Pin_Type_Injected	1


typedef struct ADC_Pin{
	bool type;
	uint8_t Sampling_Frequency;
	uint8_t Sequence;
}ADC_Pin;

typedef struct ADC_Interrupt{
	bool Normal_End_of_Conversion;
	bool Injected_Enf_of_Conversion;
}ADC_Interrupt;


typedef struct ADC_Config
{
	ADC_TypeDef *Instance;
	uint8_t resolution;
	bool Conversion_Mode;
	ADC_Interrupt *Interrupt;
	bool Watchdog_Enable;
	uint16_t Watchdog_High_Threshold;
	uint16_t Watchdog_Low_Threshold;
	bool DMA_Enable;
	ADC_Pin *ADCx0;
	ADC_Pin *ADCx1;
	ADC_Pin *ADCx2;
	ADC_Pin *ADCx3;
	ADC_Pin *ADCx4;
	ADC_Pin *ADCx5;
	ADC_Pin *ADCx6;
	ADC_Pin *ADCx7;
	ADC_Pin *ADCx8;
	ADC_Pin *ADCx9;
	ADC_Pin *ADCx10;
	ADC_Pin *ADCx11;
	ADC_Pin *ADCx12;
	ADC_Pin *ADCx13;
	ADC_Pin *ADCx14;
	ADC_Pin *ADCx15;
	ADC_Pin *ADCx16;
	ADC_Pin *ADCx17;
	ADC_Pin *ADCx18;
}ADC_Config;

void ADC_Init(ADC_Config *self);
float Get_IC_Temperature(void);

#endif /* ADC_H_ */
