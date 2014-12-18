#include "L298d.h"

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"
#include "stm32f4xx_tim.h"

#define MOTOR_MAX_VAL 1000
#define MOTOR_MIN_VAL 0

struct MotorIOConfig {
	GPIO_TypeDef * IN1_PORT;
	uint16_t IN1_PIN;
	uint8_t IN1_PIN_SOURCE;

	GPIO_TypeDef*IN2_PORT;
	uint16_t IN2_PIN;
	uint8_t IN2_PIN_SOURCE;

	GPIO_TypeDef* EN_PORT;
	uint16_t EN_PIN;

	__IO uint32_t* PWM_VALUE_1;__IO uint32_t* PWM_VALUE_2;
};

/**
 * WARNING: IN1 should be always on TIM1, IN2 on TIM3
 */
static MotorIOConfig motorIOConfig[4] = { { GPIOE, GPIO_Pin_9, GPIO_PinSource9, GPIOC, GPIO_Pin_6, GPIO_PinSource6,
GPIOB, GPIO_Pin_4, &(TIM1->CCR1), &(TIM3->CCR1) }, // MOTOR 1
        { GPIOE, GPIO_Pin_11, GPIO_PinSource11, GPIOB, GPIO_Pin_5, GPIO_PinSource5, GPIOC, GPIO_Pin_9, &(TIM1->CCR2),
                &(TIM3->CCR2) }, // MOTOR 2
        { GPIOE, GPIO_Pin_13, GPIO_PinSource13, GPIOB, GPIO_Pin_1, GPIO_PinSource1, GPIOB, GPIO_Pin_13, &(TIM1->CCR3),
                &(TIM3->CCR4) }, // MOTOR 3
        { GPIOE, GPIO_Pin_14, GPIO_PinSource14, GPIOB, GPIO_Pin_0, GPIO_PinSource0, GPIOB, GPIO_Pin_12, &(TIM1->CCR4),
                &(TIM3->CCR3) }, // MOTOR 4
        };

static std::string L298_Motor_Names[4] = { "gripper", "lidar", "shoulder", "hand" };

L298::L298() :
		SimpleMotorController( { L298_Motor_Names[0], L298_Motor_Names[1], L298_Motor_Names[2], L298_Motor_Names[3] }) {
	// Enable timers 
	{
		TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
		
		// Enable TIM1
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
		TIM_TimeBaseStructure.TIM_Period = MOTOR_MAX_VAL + 1;
		TIM_TimeBaseStructure.TIM_Prescaler = 31; //PrescalerValue;
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
		
		// Enable TIM3
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
		TIM_TimeBaseStructure.TIM_Period = MOTOR_MAX_VAL + 1;
		TIM_TimeBaseStructure.TIM_Prescaler = 15; //PrescalerValue;
		TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	}
	
	// init pwm and gpio
	{
		TIM_OCInitTypeDef TIM_OCInitStructure;
		TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
		
		// TIMER 1
		// PWM KANAL 1 
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable;
		TIM_OCInitStructure.TIM_Pulse = 0;
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
		TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
		TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
		TIM_OC1Init(TIM1, &TIM_OCInitStructure);
		TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);
		//PWM KANAL2 
		TIM_OC2Init(TIM1, &TIM_OCInitStructure);
		TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
		//PWM KANAL3 
		TIM_OC3Init(TIM1, &TIM_OCInitStructure);
		TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);
		//PWM KANAL 4
		TIM_OC4Init(TIM1, &TIM_OCInitStructure);
		TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
		
		TIM_ARRPreloadConfig(TIM1, ENABLE);
		TIM_Cmd(TIM1, ENABLE);
		TIM_CtrlPWMOutputs(TIM1, ENABLE);
		
		// TIMER 3
		TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
		TIM_OCInitStructure.TIM_Pulse = 0;
		TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
		
		// PWM KANAL 1 
		TIM_OC1Init(TIM3, &TIM_OCInitStructure);
		TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);
		//PWM KANAL2 
		TIM_OC2Init(TIM3, &TIM_OCInitStructure);
		TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
		//PWM KANAL3 
		TIM_OC3Init(TIM3, &TIM_OCInitStructure);
		TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
		//PWM KANAL 4
		TIM_OC4Init(TIM3, &TIM_OCInitStructure);
		TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
		
		TIM_ARRPreloadConfig(TIM3, ENABLE);
		TIM_Cmd(TIM3, ENABLE);
		
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
		
		GPIO_InitTypeDef GPIO_InitStructure;
		
		// init pwm pins
		for (int i = 0; i < 4; i++) {
			// EN pin
			GPIO_InitStructure.GPIO_Pin = motorIOConfig[i].EN_PIN;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(motorIOConfig[i].EN_PORT, &GPIO_InitStructure);
			
			// IN1
			GPIO_InitStructure.GPIO_Pin = motorIOConfig[i].IN1_PIN;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
			GPIO_Init(motorIOConfig[i].IN1_PORT, &GPIO_InitStructure);
			
			// set alternate function of enable pin to pwm
			GPIO_PinAFConfig(motorIOConfig[i].IN1_PORT, motorIOConfig[i].IN1_PIN_SOURCE, GPIO_AF_TIM1);
			
			/// IN2
			GPIO_InitStructure.GPIO_Pin = motorIOConfig[i].IN2_PIN;
			GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
			GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
			GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
			GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
			GPIO_Init(motorIOConfig[i].IN2_PORT, &GPIO_InitStructure);
			
			// set alternate function of enable pin to pwm
			GPIO_PinAFConfig(motorIOConfig[i].IN2_PORT, motorIOConfig[i].IN2_PIN_SOURCE, GPIO_AF_TIM3);
		}
	}
}

#define BACKWARD_FACT 0.9345

void L298::_setMotorPWM(int motor, float percent) {
	assert_param(motor >= 0 && motor <= 3);
	
	if (percent > 0.01) {
		motorIOConfig[motor].EN_PORT->BSRRL = motorIOConfig[motor].EN_PIN;
		
		*(motorIOConfig[motor].PWM_VALUE_1) = (uint32_t) (percent * MOTOR_MAX_VAL);
		*(motorIOConfig[motor].PWM_VALUE_2) = 0;
	} else if (percent < -0.01) {
		motorIOConfig[motor].EN_PORT->BSRRL = motorIOConfig[motor].EN_PIN;
		
		*(motorIOConfig[motor].PWM_VALUE_1) = 0;
		*(motorIOConfig[motor].PWM_VALUE_2) = (uint32_t) -(percent * BACKWARD_FACT * MOTOR_MAX_VAL);
	} else { // speed is 0
		motorIOConfig[motor].EN_PORT->BSRRH = motorIOConfig[motor].EN_PIN;
		
		*(motorIOConfig[motor].PWM_VALUE_1) = 0;
		*(motorIOConfig[motor].PWM_VALUE_2) = 0;
	}
}

