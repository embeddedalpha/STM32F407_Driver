/*
 * ADC.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Kunal
 */


#include "ADC.h"


void ADC_Init(void)
{
	RCC -> APB2ENR |= RCC_APB2ENR_ADC1EN;
	ADC1 -> CR2 |= ADC_CR2_ADON | ADC_CR2_CONT ;
	ADC123_COMMON -> CCR |= ADC_CCR_TSVREFE;
	ADC1 -> SMPR1 |= ADC_SMPR1_SMP18;
}

float Get_IC_Temperature(void)
{
	float v_sense = 0;
	float temp = 0;
	const float V25 = 0.76;
	const float Avg_Slope = 2.5;

	ADC1 -> CR2 |= ADC_CR2_SWSTART;
	v_sense = ((ADC1 -> DR) * 3.3)/4095;
	temp = ((v_sense - V25) / Avg_Slope)+25;
	return temp;

}
