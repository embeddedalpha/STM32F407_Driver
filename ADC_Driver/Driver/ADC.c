/*
 * ADC.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Kunal
 */


#include "ADC.h"


static void ADC_0_Pin(ADC_Config *self);
static void ADC_1_Pin(ADC_Config *self);
static void ADC_2_Pin(ADC_Config *self);
static void ADC_3_Pin(ADC_Config *self);
static void ADC_4_Pin(ADC_Config *self);
static void ADC_5_Pin(ADC_Config *self);
static void ADC_6_Pin(ADC_Config *self);
static void ADC_7_Pin(ADC_Config *self);
static void ADC_8_Pin(ADC_Config *self);
static void ADC_9_Pin(ADC_Config *self);
static void ADC_10_Pin(ADC_Config *self);
static void ADC_11_Pin(ADC_Config *self);
static void ADC_12_Pin(ADC_Config *self);
static void ADC_13_Pin(ADC_Config *self);
static void ADC_14_Pin(ADC_Config *self);
static void ADC_15_Pin(ADC_Config *self);
static void ADC_16_Pin(ADC_Config *self);

void ADC_Init(ADC_Config *self)
{
	if(self -> Instance == ADC1) RCC -> APB2ENR |= RCC_APB2ENR_ADC1EN;
	if(self -> Instance == ADC2) RCC -> APB2ENR |= RCC_APB2ENR_ADC2EN;

	self -> Instance -> SMPR1 |= (self->ADCx18->Sampling_Frequency << 24)	|
								 (self->ADCx17->Sampling_Frequency << 21)	|
								 (self->ADCx16->Sampling_Frequency << 18)	|
								 (self->ADCx15->Sampling_Frequency << 15)	|
								 (self->ADCx14->Sampling_Frequency << 12)	|
								 (self->ADCx13->Sampling_Frequency <<  9)	|
								 (self->ADCx12->Sampling_Frequency <<  6)	|
								 (self->ADCx11->Sampling_Frequency <<  3)	|
								 (self->ADCx10->Sampling_Frequency <<  0)	;

	self -> Instance -> SMPR2 |= (self->ADCx9->Sampling_Frequency << 27)	|
								 (self->ADCx8->Sampling_Frequency << 24)	|
								 (self->ADCx7->Sampling_Frequency << 21)	|
								 (self->ADCx6->Sampling_Frequency << 18)	|
								 (self->ADCx5->Sampling_Frequency << 16)	|
								 (self->ADCx4->Sampling_Frequency << 12)	|
								 (self->ADCx3->Sampling_Frequency <<  9)	|
								 (self->ADCx2->Sampling_Frequency <<  6)	|
								 (self->ADCx1->Sampling_Frequency <<  3)	|
								 (self->ADCx0->Sampling_Frequency <<  0)	;

/*########################################################################################################*/
	ADC_0_Pin(self);
	ADC_1_Pin(self);
	ADC_2_Pin(self);
	ADC_3_Pin(self);
	ADC_4_Pin(self);
	ADC_5_Pin(self);
	ADC_6_Pin(self);
	ADC_7_Pin(self);
	ADC_8_Pin(self);
	ADC_9_Pin(self);
	ADC_10_Pin(self);
	ADC_11_Pin(self);
	ADC_12_Pin(self);
	ADC_13_Pin(self);
	ADC_14_Pin(self);
	ADC_15_Pin(self);
	ADC_16_Pin(self);
/*########################################################################################################*/

	self -> Instance -> CR2 |= ADC_CR2_ADON;
	self -> Instance -> CR2 |=  self -> Conversion_Mode ;

}


void ADC_Internal_Temp_Activate(ADC_Config *self)
{
	self -> Instance -> SMPR1 |= ADC_SMPR1_SMP18;
	ADC123_COMMON -> CCR |= ADC_CCR_TSVREFE;
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




static void ADC_0_Pin(ADC_Config *self)
{
    if(self->ADCx0->Sequence >= 13 && self->ADCx0->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 0 << (self->ADCx0->Sequence - 13)*5;
    }
    if(self->ADCx0->Sequence >= 7 && self->ADCx0->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 0 << (self->ADCx0->Sequence - 7)*5;
    }
    if(self->ADCx0->Sequence >= 1 && self->ADCx0->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 0 << (self->ADCx0->Sequence - 1)*5;
    }
}


static void ADC_1_Pin(ADC_Config *self)
{
    if(self->ADCx1->Sequence >= 13 && self->ADCx1->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 1 << (self->ADCx1->Sequence - 13)*5;
    }
    if(self->ADCx1->Sequence >= 7 && self->ADCx1->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 1 << (self->ADCx1->Sequence - 7)*5;
    }
    if(self->ADCx1->Sequence >= 1 && self->ADCx1->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 1 << (self->ADCx1->Sequence - 1)*5;
    }
}


static void ADC_2_Pin(ADC_Config *self)
{
    if(self->ADCx2->Sequence >= 13 && self->ADCx2->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 2 << (self->ADCx2->Sequence - 13)*5;
    }
    if(self->ADCx2->Sequence >= 7 && self->ADCx2->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 2 << (self->ADCx2->Sequence - 7)*5;
    }
    if(self->ADCx2->Sequence >= 1 && self->ADCx2->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 2 << (self->ADCx2->Sequence - 1)*5;
    }
}


static void ADC_3_Pin(ADC_Config *self)
{
    if(self->ADCx3->Sequence >= 13 && self->ADCx3->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 3 << (self->ADCx3->Sequence - 13)*5;
    }
    if(self->ADCx3->Sequence >= 7 && self->ADCx3->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 3 << (self->ADCx3->Sequence - 7)*5;
    }
    if(self->ADCx3->Sequence >= 1 && self->ADCx3->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 3 << (self->ADCx3->Sequence - 1)*5;
    }
}


static void ADC_4_Pin(ADC_Config *self)
{
    if(self->ADCx4->Sequence >= 13 && self->ADCx4->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 4 << (self->ADCx4->Sequence - 13)*5;
    }
    if(self->ADCx4->Sequence >= 7 && self->ADCx4->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 4 << (self->ADCx4->Sequence - 7)*5;
    }
    if(self->ADCx4->Sequence >= 1 && self->ADCx4->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 4 << (self->ADCx4->Sequence - 1)*5;
    }
}


static void ADC_5_Pin(ADC_Config *self)
{
    if(self->ADCx5->Sequence >= 13 && self->ADCx5->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 5 << (self->ADCx5->Sequence - 13)*5;
    }
    if(self->ADCx5->Sequence >= 7 && self->ADCx5->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 5 << (self->ADCx5->Sequence - 7)*5;
    }
    if(self->ADCx5->Sequence >= 1 && self->ADCx5->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 5 << (self->ADCx5->Sequence - 1)*5;
    }
}


static void ADC_6_Pin(ADC_Config *self)
{
    if(self->ADCx6->Sequence >= 13 && self->ADCx6->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 6 << (self->ADCx6->Sequence - 13)*5;
    }
    if(self->ADCx6->Sequence >= 7 && self->ADCx6->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 6 << (self->ADCx6->Sequence - 7)*5;
    }
    if(self->ADCx6->Sequence >= 1 && self->ADCx6->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 6 << (self->ADCx6->Sequence - 1)*5;
    }
}


static void ADC_7_Pin(ADC_Config *self)
{
    if(self->ADCx7->Sequence >= 13 && self->ADCx7->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 7 << (self->ADCx7->Sequence - 13)*5;
    }
    if(self->ADCx7->Sequence >= 7 && self->ADCx7->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 7 << (self->ADCx7->Sequence - 7)*5;
    }
    if(self->ADCx7->Sequence >= 1 && self->ADCx7->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 7 << (self->ADCx7->Sequence - 1)*5;
    }
}


static void ADC_8_Pin(ADC_Config *self)
{
    if(self->ADCx8->Sequence >= 13 && self->ADCx8->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 8 << (self->ADCx8->Sequence - 13)*5;
    }
    if(self->ADCx8->Sequence >= 7 && self->ADCx8->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 8 << (self->ADCx8->Sequence - 7)*5;
    }
    if(self->ADCx8->Sequence >= 1 && self->ADCx8->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 8 << (self->ADCx8->Sequence - 1)*5;
    }
}


static void ADC_9_Pin(ADC_Config *self)
{
    if(self->ADCx9->Sequence >= 13 && self->ADCx9->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 9 << (self->ADCx9->Sequence - 13)*5;
    }
    if(self->ADCx9->Sequence >= 7 && self->ADCx9->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 9 << (self->ADCx9->Sequence - 7)*5;
    }
    if(self->ADCx9->Sequence >= 1 && self->ADCx9->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 9 << (self->ADCx9->Sequence - 1)*5;
    }
}


static void ADC_10_Pin(ADC_Config *self)
{
    if(self->ADCx10->Sequence >= 13 && self->ADCx10->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 10 << (self->ADCx10->Sequence - 13)*5;
    }
    if(self->ADCx10->Sequence >= 7 && self->ADCx10->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 10 << (self->ADCx10->Sequence - 7)*5;
    }
    if(self->ADCx10->Sequence >= 1 && self->ADCx10->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 10 << (self->ADCx10->Sequence - 1)*5;
    }
}


static void ADC_11_Pin(ADC_Config *self)
{
    if(self->ADCx11->Sequence >= 13 && self->ADCx11->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 11 << (self->ADCx11->Sequence - 13)*5;
    }
    if(self->ADCx11->Sequence >= 7 && self->ADCx11->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 11 << (self->ADCx11->Sequence - 7)*5;
    }
    if(self->ADCx11->Sequence >= 1 && self->ADCx11->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 11 << (self->ADCx11->Sequence - 1)*5;
    }
}


static void ADC_12_Pin(ADC_Config *self)
{
    if(self->ADCx12->Sequence >= 13 && self->ADCx12->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 12 << (self->ADCx12->Sequence - 13)*5;
    }
    if(self->ADCx12->Sequence >= 7 && self->ADCx12->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 12 << (self->ADCx12->Sequence - 7)*5;
    }
    if(self->ADCx12->Sequence >= 1 && self->ADCx12->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 12 << (self->ADCx12->Sequence - 1)*5;
    }
}


static void ADC_13_Pin(ADC_Config *self)
{
    if(self->ADCx13->Sequence >= 13 && self->ADCx13->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 13 << (self->ADCx13->Sequence - 13)*5;
    }
    if(self->ADCx13->Sequence >= 7 && self->ADCx13->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 13 << (self->ADCx13->Sequence - 7)*5;
    }
    if(self->ADCx13->Sequence >= 1 && self->ADCx13->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 13 << (self->ADCx13->Sequence - 1)*5;
    }
}


static void ADC_14_Pin(ADC_Config *self)
{
    if(self->ADCx14->Sequence >= 13 && self->ADCx14->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 14 << (self->ADCx14->Sequence - 13)*5;
    }
    if(self->ADCx14->Sequence >= 7 && self->ADCx14->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 14 << (self->ADCx14->Sequence - 7)*5;
    }
    if(self->ADCx14->Sequence >= 1 && self->ADCx14->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 14 << (self->ADCx14->Sequence - 1)*5;
    }
}


static void ADC_15_Pin(ADC_Config *self)
{
    if(self->ADCx15->Sequence >= 13 && self->ADCx15->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 15 << (self->ADCx15->Sequence - 13)*5;
    }
    if(self->ADCx15->Sequence >= 7 && self->ADCx15->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 15 << (self->ADCx15->Sequence - 7)*5;
    }
    if(self->ADCx15->Sequence >= 1 && self->ADCx15->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 15 << (self->ADCx15->Sequence - 1)*5;
    }
}


static void ADC_16_Pin(ADC_Config *self)
{
    if(self->ADCx16->Sequence >= 13 && self->ADCx16->Sequence <= 16)
    {
        self -> Instance -> SQR1 |= 16 << (self->ADCx16->Sequence - 13)*5;
    }
    if(self->ADCx16->Sequence >= 7 && self->ADCx16->Sequence <= 12)
    {
        self -> Instance -> SQR2 |= 16 << (self->ADCx16->Sequence - 7)*5;
    }
    if(self->ADCx16->Sequence >= 1 && self->ADCx16->Sequence <= 6)
    {
        self -> Instance -> SQR3 |= 16 << (self->ADCx16->Sequence - 1)*5;
    }
}


