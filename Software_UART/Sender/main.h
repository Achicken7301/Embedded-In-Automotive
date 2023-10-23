#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"

#include "delay.h"

#define Tfull 500
#define Thalf Tfull/2


#define TX_PIN GPIO_Pin_8
#define RX_PIN GPIO_Pin_9


void softUART_TransmitInit();
void UART_writeByte(uint8_t data);
void softUART_ReceiveInit();
uint8_t UART_readByte(); 
#endif