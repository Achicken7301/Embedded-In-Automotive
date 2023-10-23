#ifndef __SOFTWARE_TIMER_H__
#define __SOFTWARE_TIMER_H__

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

extern int timer_flag;

void TIM2_INT_Init();

void timerRun();
void setTimer(int duration);

#endif