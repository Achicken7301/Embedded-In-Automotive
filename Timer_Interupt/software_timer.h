#ifndef __SOFTWARE_TIMER_H__
#define __SOFTWARE_TIMER_H__

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

extern int timer_flag;

void TIM2_INT_Init();

void delay_ms(uint16_t ms);
void delay_s(uint16_t s);
void timerRun();
void setTimer(int duration);

#endif