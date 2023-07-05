#include "software_timer.h"
#define CLOCK_TICK 10

int timer_flag = 0;
int timer_counter = 0;

void timerRun()
{
	if (timer_counter > 0)
	{
		timer_counter--;
		if (timer_counter <= 0)
		{
			timer_flag = 1;
		}
	}
}

void setTimer(int duration)
{
	timer_counter = duration / CLOCK_TICK;
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

	// T = 10ms => f = 100Hz
	TIM_TimeBaseInitStruct.TIM_Prescaler = 720 - 1;
	TIM_TimeBaseInitStruct.TIM_Period = 1000 - 1;
	
	// T = 1ms => f = 1000Hz
	//TIM_TimeBaseInitStruct.TIM_Prescaler = 8 - 1;
	//TIM_TimeBaseInitStruct.TIM_Period = 9000 - 1;

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