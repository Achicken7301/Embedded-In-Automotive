#ifndef __SOFTWARE_UART_H__
#define __SOFTWARE_UART_H__

#include "Dio.h"
#include "delay.h"

#define Tfull 100*1000
#define Thalf Tfull/2

typedef struct
{
	Dio_Port port;
	Dio_Pin pin_number;
} Soft_uartPin;

typedef struct SoftUART_InitPin
{
	Soft_uartPin TX;
	Soft_uartPin RX;
	
} SoftUART_InitPin;

#endif