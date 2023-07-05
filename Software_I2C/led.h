#ifndef __LED_H__
#define __LED_H__
#define NO_OF_LED 5

#define INIT_MODE1 0
#define LED1_MODE1 1
#define LED2_MODE1 2
#define LED3_MODE1 3
#define LED4_MODE1 4
#define LED5_MODE1 5

#define INIT_MODE2 10
#define LED1_MODE2 11
#define LED2_MODE2 12
#define LED3_MODE2 13
#define LED4_MODE2 14
#define LED5_MODE2 15

#include "stm32f10x.h"
#include "software_timer.h"
#include "Dio.h"
#include "button.h"

extern uint16_t led_arr[NO_OF_LED];

void fsm_led_mode_1();
void fsm_led_mode_2();

#endif