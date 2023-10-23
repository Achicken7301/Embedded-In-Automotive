#ifndef __DIO_H__
#define __DIO_H__
#include "stm32f10x.h"

/**
 * @brief Port and Pin
 *
 */
// typedef enum
// {
// 	DIO_CHANNEL_PA0,
// 	DIO_CHANNEL_PA1,
// 	DIO_CHANNEL_PA2,
// 	DIO_CHANNEL_PA3,
// 	DIO_CHANNEL_PA4,
// 	DIO_CHANNEL_PA5,
// 	DIO_CHANNEL_PA6,
// 	DIO_CHANNEL_PA7,
// 	DIO_CHANNEL_PA8,
// 	DIO_CHANNEL_PA9,
// 	DIO_CHANNEL_PA10,
// 	DIO_CHANNEL_PA11,
// 	DIO_CHANNEL_PA12,
// 	DIO_CHANNEL_PA13,
// 	DIO_CHANNEL_PA14,
// 	DIO_CHANNEL_PA15,
// 	DIO_CHANNEL_PB0,
// 	DIO_CHANNEL_PB1,
// 	DIO_CHANNEL_PB2,
// 	DIO_CHANNEL_PB3,
// 	DIO_CHANNEL_PB4,
// 	DIO_CHANNEL_PB5,
// 	DIO_CHANNEL_PB6,
// 	DIO_CHANNEL_PB7,
// 	DIO_CHANNEL_PB8,
// 	DIO_CHANNEL_PB9,
// 	DIO_CHANNEL_PB10,
// 	DIO_CHANNEL_PB11,
// 	DIO_CHANNEL_PB12,
// 	DIO_CHANNEL_PB13,
// 	DIO_CHANNEL_PB14,
// 	DIO_CHANNEL_PB15,
// 	DIO_CHANNEL_PC0,
// 	DIO_CHANNEL_PC1,
// 	DIO_CHANNEL_PC2,
// 	DIO_CHANNEL_PC3,
// 	DIO_CHANNEL_PC4,
// 	DIO_CHANNEL_PC5,
// 	DIO_CHANNEL_PC6,
// 	DIO_CHANNEL_PC7,
// 	DIO_CHANNEL_PC8,
// 	DIO_CHANNEL_PC9,
// 	DIO_CHANNEL_PC10,
// 	DIO_CHANNEL_PC11,
// 	DIO_CHANNEL_PC12,
// 	DIO_CHANNEL_PC13,
// 	DIO_CHANNEL_PC14,
// 	DIO_CHANNEL_PC15
// } Dio_channel_type;


typedef enum{
	Dio_PortA,
	Dio_PortB,
	Dio_PortC
}Dio_Port;

typedef enum{
	Dio_Pin_0,
	Dio_Pin_1,
	Dio_Pin_2,
	Dio_Pin_3,
	Dio_Pin_4,
	Dio_Pin_5,
	Dio_Pin_6,
	Dio_Pin_7,
	Dio_Pin_8,
	Dio_Pin_9,
	Dio_Pin_10,
	Dio_Pin_11,
	Dio_Pin_12,
	Dio_Pin_13,
	Dio_Pin_14,
	Dio_Pin_15
}Dio_Pin;


/**
 * @brief Level HIGH or LOW
 * 
 */
typedef enum
{
	STD_LOW,
	STD_HIGH
} Dio_LevelType;

void Dio_WriteChannel(Dio_Port port, Dio_Pin pin, Dio_LevelType Level);
// void Dio_WriteChannel(Dio_channel_type ChannelID, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel(Dio_Port port, Dio_Pin pin);

/**
 * @brief initialize a pin mode
 * 
 * @param channelid pin
 * @param type 
 */
// void pinConfig(Dio_channel_type channelid, GPIOMode_TypeDef type);

// Default speed 2MHz
void pinMode(Dio_Port port, Dio_Pin pin, GPIOMode_TypeDef type);
#endif