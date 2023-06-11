#include "software_timer.h"
#define CLOCK_TICK 1000*1000

int timer_flag = 0;
int timer_counter = 0;

void timerRun(){
	if(timer_counter > 0){
		timer_counter--;
		if(timer_counter <= 0){
			timer_flag = 1;
		}
	}
}

void setTimer(int duration){
	timer_counter = duration;
	timer_flag = 0;
}


void TIM2_INT_Init()
{
	// Init struct
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	// Enable clock for TIM2
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	// TIM2 initialization for overflow every 500ms
	// Update Event (Hz) = timer_clock / ((TIM_Prescaler + 1) * (TIM_Period + 1))
	// Update Event (Hz) = 72MHz / ((3599 + 1) * (9999 + 1)) = 2Hz (0.5s)
	// f = 1000Hz ~ t = 1ms -> 72Mhz / (72 * 1000)
	
	// 1ms
	TIM_TimeBaseInitStruct.TIM_Prescaler = 72 - 1;
	TIM_TimeBaseInitStruct.TIM_Period = 1000 - 1;
	
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
	
	// Enable TIM2 interrupt
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	// Start TIM2
	TIM_Cmd(TIM2, ENABLE);
	
	// Nested vectored interrupt settings
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
}

void delay_ms(uint16_t ms){
	TIM2->CNT = 0;
	while(TIM2->CNT < ms);
}

void delay_s(uint16_t s){
	for(uint16_t i = 0; i < s; i++){
		delay_ms(1000);		
	}
}
