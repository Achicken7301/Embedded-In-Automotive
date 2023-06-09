#ifndef __HARDWARE_SPI_H__
#define __HARDWARE_SPI_H__
#include "stm32f10x.h"
#include "delay.h"
#include "Dio.h"
#include "stm32f10x_spi.h"

#define SPIx_RCC 		RCC_APB2Periph_SPI1
#define SPIx 			SPI1
#define SPI_GPIO_RCC 	RCC_APB2Periph_GPIOA
#define SPI_GPIO 		GPIOA
#define SPI_PIN_MOSI 	GPIO_Pin_7
#define SPI_PIN_MISO 	GPIO_Pin_6
#define SPI_PIN_SCK 	GPIO_Pin_5
#define SPI_PIN_SS 		GPIO_Pin_4

void SPIx_Init();
uint8_t SPIx_Transfer(uint8_t data);
void SPIx_EnableSlave();
void SPIx_DisableSlave();
#endif