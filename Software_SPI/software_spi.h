#ifndef __SOFTWARE_SPI_H__
#define __SOFTWARE_SPI_H__
#include "stm32f10x.h"
#include "delay.h"
#include "Dio.h"

typedef struct{
	Dio_Port port;
	Dio_Pin pin_number;
}SPI_pin;

typedef struct {
	SPI_pin SCK;
	SPI_pin SS;
	SPI_pin MISO;
	SPI_pin MOSI;
} SoftSPI_InitPin;

void spiInit(SoftSPI_InitPin *SPI_pin);
uint8_t SPI_transfer(SoftSPI_InitPin *pin,  uint8_t byte_out);
void SPI_Start(SoftSPI_InitPin *SPI_pin);
void SPI_End(SoftSPI_InitPin *SPI_pin);

#endif