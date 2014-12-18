/*
 * ArmController.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: jgdo
 */

#include "ArmPositionReader.h"
#include <functional>
#include <ros.h>
#include <cstdio>
#include <algorithm>

using namespace ml;

const ArmPositionReader::ADC_ConfigS ArmPositionReader::adcConfig[4] = { { GPIOC, GPIO_Pin_1, RCC_AHB1Periph_GPIOC,
ADC_Channel_11 }, { GPIOC, GPIO_Pin_5, RCC_AHB1Periph_GPIOC, ADC_Channel_15 }, { GPIOA, GPIO_Pin_3,
RCC_AHB1Periph_GPIOA, ADC_Channel_3 }, { GPIOA, GPIO_Pin_1, RCC_AHB1Periph_GPIOA, ADC_Channel_1 } };

static std::function<void(void)> armControllerTimerCallback;

ArmPositionReader::ArmPositionReader() :
		raw_pub("/joint0_raw", &raw_msg), raw_pub_timer(1, std::bind(&ArmPositionReader::publishRaw, this)), adc_timer(
		        1, std::bind(&ArmPositionReader::updateADC, this)) {
	nodeHandle.advertise(raw_pub);
	
	lastSamplingTime = SystemMillisDouble();
	
	armControllerTimerCallback = std::bind(&ArmPositionReader::adcISR, this);
	
	DMA_InitTypeDef DMA_InitStructure;
	
	// Clock Enable
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);
//	
//	// DMA-Disable
//	DMA_Cmd(DMA2_Stream0, DISABLE);
//	DMA_DeInit(DMA2_Stream0);
//	
//	// DMA2-Config
//	DMA_InitStructure.DMA_Channel = DMA_Channel_0;
//	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) &(ADC1->DR);
//	DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t) adc_dma_buf;
//	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
//	DMA_InitStructure.DMA_BufferSize = NUM_ADC_CHANS;
//	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
//	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
//	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
//	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
//	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
//	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
//	DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
//	DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_HalfFull;
//	DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
//	DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
//	DMA_Init(DMA2_Stream0, &DMA_InitStructure);
//	DMA_Cmd(DMA2_Stream0, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	
	// Configure GPIO
	for (int i = 0; i < 4; i++) {
		RCC_AHB1PeriphClockCmd(adcConfig[i].ADC_CLK, ENABLE);
		GPIO_InitTypeDef gpioInit;
		
		gpioInit.GPIO_Pin = adcConfig[i].ADC_PIN;
		gpioInit.GPIO_Mode = GPIO_Mode_AN;
		gpioInit.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(adcConfig[i].ADC_PORT, &gpioInit);
	}
	
	// Configure ADC
	ADC_InitTypeDef ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	
	ADC_StructInit(&ADC_InitStructure);
	
	// ADC-Config
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div4;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);
	
	/* ADC1 Configuration */
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
//	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
//	ADC_InitStructure.ADC_NbrOfConversion = NUM_ADC_CHANS;
	ADC_InitStructure.ADC_NbrOfConversion = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	
//	ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);
//	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);   // Enable ADC1  
	        
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	// Clock enable
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// Timer disable
	TIM_Cmd(TIM2, DISABLE);
	
	// Timer init
	TIM_TimeBaseStructure.TIM_Period = 4199;
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	// Timer preload enable
	TIM_ARRPreloadConfig(TIM2, ENABLE);
	
	NVIC_InitTypeDef NVIC_InitStructure;
	
	// Update Interrupt enable
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	// NVIC konfig
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

float ArmPositionReader::getServoRawPosition(int num) {
	return (float) adc_sum_values[num] / (float) NUM_MOV_AVG;
//	ADC_RegularChannelConfig(ADC1, adcConfig[num].ADC_CH, 1, ADC_SampleTime_15Cycles);
//	ADC_SoftwareStartConv(ADC1);
//	while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)
//		;
//	return ADC_GetConversionValue(ADC1);
}

void ArmPositionReader::updateADC() {
	int adc_buf[4];
	while (!adc_queue.empty()) {
		uint64_t val = adc_queue.pop();
		
		adc_buf[0] = val & 0xffff;
		adc_buf[1] = (val >> 16) & 0xffff;
		adc_buf[2] = (val >> 32) & 0xffff;
		adc_buf[3] = (val >> 48) & 0xffff;
		
		for (int i = 0; i < NUM_ADC_CHANS; i++) {
			// adc_set[i].insert(adc_buf[i]);
			adc_set[i][adc_counter] = adc_buf[i];
		}
		
		if (adc_counter < NUM_MOV_AVG - 1)
			adc_counter++;
		else {
			adc_counter = 0;
			
			for (int i = 0; i < NUM_ADC_CHANS; i++) {
				//adc_sum_values[i] = adc_set[i].median() * NUM_MOV_AVG;
				//adc_set[i].clear();
				std::sort(adc_set[i].begin(), adc_set[i].end());
				adc_sum_values[i] = adc_set[i][NUM_MOV_AVG/2];
			}
		}
	}
}

void ArmPositionReader::publishRaw() {
	raw_msg.data = adc_dma_buf[0];
	raw_pub.publish(&raw_msg);
}

void ArmPositionReader::adcISR() {
//	for (int i = 0; i < NUM_ADC_CHANS; i++) {
//		adc_set[i].insert(adc_dma_buf[i]);
//	}
//	
//	if(adc_counter < NUM_MOV_AVG)
//		adc_counter++;
//	else {
//		adc_counter = 0;
//		
//		for (int i = 0; i < NUM_ADC_CHANS; i++) {
//			adc_sum_values[i] = adc_set[i].median() * NUM_MOV_AVG;
//			adc_set[i].clear();
//		}
//	}
	
	for (int i = 0; i < NUM_ADC_CHANS; i++) {
		ADC_RegularChannelConfig(ADC1, adcConfig[i].ADC_CH, 1, ADC_SampleTime_3Cycles);
		ADC_SoftwareStartConv(ADC1);
		while (ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET)
			;
		adc_dma_buf[i] = ADC_GetConversionValue(ADC1);
	}
	
	uint64_t val = (uint64_t) adc_dma_buf[0] | ((uint64_t)adc_dma_buf[1] << 16ULL) | ((uint64_t)adc_dma_buf[2] << 32ULL)
	        | ((uint64_t)adc_dma_buf[3] << 48ULL);
	adc_queue.append(val);
	
// process previous values
//	for (int i = 0; i < NUM_ADC_CHANS; i++) {
//		int current = adc_sum_values[i];
//		int adc_val = adc_dma_buf[i];
//		int idx = moving_average_idx[i];
//		
//		current -= moving_average_values[i][idx];
//		current += adc_val;
//		moving_average_values[i][idx] = adc_val;
//		if (idx < NUM_MOV_AVG - 1)
//			moving_average_idx[i] = idx + 1;
//		else
//			moving_average_idx[i] = 0;
//		
//		adc_sum_values[i] = current;
//	}
	
//	
//	for (int chan = 0; chan < NUM_ADC_CHANS; chan++) {
//		int idx = moving_average_idx[chan];
//		if (idx < NUM_MOV_AVG - 1)
//			moving_average_idx[chan] = idx + 1;
//		else
//			moving_average_idx[chan] = 0;
//		
//		int adc_val = adc_dma_buf[chan];
//		moving_average_values[chan][idx] = adc_val;
//		
//		int sum = 0;
//		for (int i = 0; i < NUM_MOV_AVG; i++)
//			sum += moving_average_values[chan][i];
//		
//		adc_sum_values[chan] = sum;
//	}
	
//	for (int i = 0; i < NUM_ADC_CHANS; i++) {
//		adc_sum_values[i] = adc_dma_buf[i] * NUM_MOV_AVG;
//	}
	
//	// start new round
//	for (int i = 0; i < NUM_ADC_CHANS; i++)
//		ADC_RegularChannelConfig(ADC1, adcConfig[i].ADC_CH, i + 1, ADC_SampleTime_15Cycles);
	
// 	ADC_SoftwareStartConv(ADC1); //Start ADC1 Conversion
}

extern "C" void TIM2_IRQHandler(void) {
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) {
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		if (armControllerTimerCallback)
			armControllerTimerCallback();
	}
}

void ArmPositionReader::updateJointState() {
	const float pos_v = 0.9;
	const float vel_v = 0.8;
	
	Vec2f prev_pos = joint_p;
	
	Vec2f measured;
	measured(0) = -(getServoRawPosition(SERVO_SHOULDER) * -0.000828042 + 2.4717064) + M_PI_2;
	measured(1) = -(getServoRawPosition(SERVO_HAND) * 0.00084679 - 1.5724899) + 0.04;
	
//	joint_p(0) = joint_p(0) * pos_v
//	        - ((getServoRawPosition(SERVO_SHOULDER) * -0.000828042 + 2.4717064) - M_PI_2) * (1 - pos_v);
//	joint_p(1) = joint_p(1) * pos_v - ((getServoRawPosition(SERVO_HAND) * 0.00084679 - 1.5724899) + 0.04) * (1 - pos_v);
	
	joint_p = measured * pos_v + prev_pos * (1 - pos_v);
	
	double now = SystemMillisDouble();
	double dt = (now - lastSamplingTime) / 1000.0;
	if (dt < 0) {
		return;
	}
	
	if (fabs(dt) < 1e-3)
		return;
	
	lastSamplingTime = now;
	
	double dtInv = 1.0 / dt;
	
	joint_v = joint_v * vel_v + (joint_p - prev_pos) * dtInv * (1 - vel_v);
	
	if (fabs(joint_v(0)) > 1e10 || fabs(joint_v(1) > 1e10)) {
		printf("error\n");
	}
}
