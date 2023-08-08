#ifndef __CAN_H__
#define __CAN_H__

#include "main.h"

typedef struct
{
	uint8_t SJW;
	uint8_t BJ1;
	uint8_t BJ2;
	uint8_t Prescaler;
	uint32_t FilterMaskId;
	uint32_t FilterId;
	uint8_t TxBufferId;
	uint8_t RxBufferId;
} Can_ConfigType;

typedef uint8_t Std_ReturnType;

#define E_OK ((Std_ReturnType)0x00U)
#define E_NOT_OK ((Std_ReturnType)0x01U)

typedef uint16_t CAN_HwHandleType;

typedef struct
{
	PduIdType

} Can_PduType;

#endif