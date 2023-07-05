#include "Dio.h"
#include "stm32f10x.h"

void enablePortClock(GPIO_InitTypeDef *gpio, Dio_Port *port){
	switch (*port)
  {
  	case Dio_PortA:
			// enable clock for portA
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
			GPIO_Init(GPIOA, gpio);
  		break;
  	case Dio_PortB:
			// enable clock for portB
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
			GPIO_Init(GPIOB, gpio);
  		break;
  	case Dio_PortC:
			// enable clock for portC
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
			GPIO_Init(GPIOC, gpio);
  		break;
  	default:
  		break;
  }
}

void pinSelect(GPIO_InitTypeDef *gpio, Dio_Pin *pin){
	
}

void pinMode(Dio_Port port, Dio_Pin pin, GPIOMode_TypeDef type){
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = type;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;
	
	// each type set clock and seperate port and pin
	switch (type)
	{
		case GPIO_Mode_IPU:
			
			break;
		case GPIO_Mode_Out_PP:
			pinSelect(&gpio, &pin);
			enablePortClock(&gpio, &port);
			break;
		default:
			break;
	}
}

/**
 * @brief config DIO mode (INPUT - OUPUT - PULLUP - PULLDOWN)
 *
 */
void pinConfig(Dio_channel_type channelid, GPIOMode_TypeDef type)
{
	GPIO_InitTypeDef gpio;

	gpio.GPIO_Mode = type;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;

	switch (channelid)
	{
	case DIO_CHANNEL_PA0:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_0;
		break;
	case DIO_CHANNEL_PA1:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_1;
		break;
	case DIO_CHANNEL_PA2:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_2;
		break;
	case DIO_CHANNEL_PA3:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_3;
		break;
	case DIO_CHANNEL_PA4:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_4;
		break;
	case DIO_CHANNEL_PA5:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_5;
		break;
	case DIO_CHANNEL_PA6:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_6;
		break;
	case DIO_CHANNEL_PA7:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_7;
		break;
	case DIO_CHANNEL_PA8:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_8;
		break;
	case DIO_CHANNEL_PA9:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_9;
		break;
	case DIO_CHANNEL_PA10:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_10;
		break;
	case DIO_CHANNEL_PA11:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_11;
		break;
	case DIO_CHANNEL_PA12:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_12;
		break;
	case DIO_CHANNEL_PA13:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_13;
		break;
	case DIO_CHANNEL_PA14:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_14;
		break;
	case DIO_CHANNEL_PA15:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_15;
		break;
	case DIO_CHANNEL_PB0:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_0;
		break;
	case DIO_CHANNEL_PB1:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_1;
		break;
	case DIO_CHANNEL_PB2:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_2;
		break;
	case DIO_CHANNEL_PB3:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_3;
		break;
	case DIO_CHANNEL_PB4:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_4;
		break;
	case DIO_CHANNEL_PB5:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_5;
		break;
	case DIO_CHANNEL_PB6:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_6;
		break;
	case DIO_CHANNEL_PB7:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_7;
		break;
	case DIO_CHANNEL_PB8:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_8;
		break;
	case DIO_CHANNEL_PB9:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_9;
		break;
	case DIO_CHANNEL_PB10:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_10;
		break;
	case DIO_CHANNEL_PB11:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_11;
		break;
	case DIO_CHANNEL_PB12:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_12;
		break;
	case DIO_CHANNEL_PB13:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_13;
		break;
	case DIO_CHANNEL_PB14:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_14;
		break;
	case DIO_CHANNEL_PB15:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_15;
		break;
	case DIO_CHANNEL_PC0:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_0;
		break;
	case DIO_CHANNEL_PC1:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_1;
		break;
	case DIO_CHANNEL_PC2:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_2;
		break;
	case DIO_CHANNEL_PC3:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_3;
		break;
	case DIO_CHANNEL_PC4:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_4;
		break;
	case DIO_CHANNEL_PC5:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_5;
		break;
	case DIO_CHANNEL_PC6:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_6;
		break;
	case DIO_CHANNEL_PC7:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_7;
		break;
	case DIO_CHANNEL_PC8:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_8;
		break;
	case DIO_CHANNEL_PC9:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_9;
		break;
	case DIO_CHANNEL_PC10:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_10;
		break;
	case DIO_CHANNEL_PC11:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_11;
		break;
	case DIO_CHANNEL_PC12:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_12;
		break;
	case DIO_CHANNEL_PC13:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_13;
		break;
	case DIO_CHANNEL_PC14:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_14;
		break;
	case DIO_CHANNEL_PC15:
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
		gpio.GPIO_Pin = GPIO_Pin_15;
		break;

	default:
		break;
	}

	GPIO_Init(GPIOA, &gpio);
	GPIO_Init(GPIOB, &gpio);
	GPIO_Init(GPIOC, &gpio);
}


void Dio_WriteChannel(Dio_channel_type ChannelId, Dio_LevelType Level)
{
	GPIO_TypeDef *gpioPort;
	uint16_t gpioPin;

	switch (ChannelId)
	{
	case DIO_CHANNEL_PA0:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_0;
		break;
	case DIO_CHANNEL_PA1:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_1;
		break;
	case DIO_CHANNEL_PA2:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_2;
		break;
	case DIO_CHANNEL_PA3:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_3;
		break;
	case DIO_CHANNEL_PA4:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_4;
		break;
	case DIO_CHANNEL_PA5:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_5;
		break;
	case DIO_CHANNEL_PA6:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_6;
		break;
	case DIO_CHANNEL_PA7:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_7;
		break;
	case DIO_CHANNEL_PA8:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_8;
		break;
	case DIO_CHANNEL_PA9:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_9;
		break;
	case DIO_CHANNEL_PA10:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_10;
		break;
	case DIO_CHANNEL_PA11:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_11;
		break;
	case DIO_CHANNEL_PA12:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_12;
		break;
	case DIO_CHANNEL_PA13:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_13;
		break;
	case DIO_CHANNEL_PA14:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_14;
		break;
	case DIO_CHANNEL_PA15:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_15;
		break;
	case DIO_CHANNEL_PB0:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_0;
		break;
	case DIO_CHANNEL_PB1:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_1;
		break;
	case DIO_CHANNEL_PB2:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_2;
		break;
	case DIO_CHANNEL_PB3:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_3;
		break;
	case DIO_CHANNEL_PB4:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_4;
		break;
	case DIO_CHANNEL_PB5:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_5;
		break;
	case DIO_CHANNEL_PB6:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_6;
		break;
	case DIO_CHANNEL_PB7:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_7;
		break;
	case DIO_CHANNEL_PB8:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_8;
		break;
	case DIO_CHANNEL_PB9:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_9;
		break;
	case DIO_CHANNEL_PB10:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_10;
		break;
	case DIO_CHANNEL_PB11:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_11;
		break;
	case DIO_CHANNEL_PB12:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_12;
		break;
	case DIO_CHANNEL_PB13:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_13;
		break;
	case DIO_CHANNEL_PB14:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_14;
		break;
	case DIO_CHANNEL_PB15:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_15;
		break;
	case DIO_CHANNEL_PC0:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_0;
		break;
	case DIO_CHANNEL_PC1:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_1;
		break;
	case DIO_CHANNEL_PC2:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_2;
		break;
	case DIO_CHANNEL_PC3:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_3;
		break;
	case DIO_CHANNEL_PC4:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_4;
		break;
	case DIO_CHANNEL_PC5:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_5;
		break;
	case DIO_CHANNEL_PC6:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_6;
		break;
	case DIO_CHANNEL_PC7:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_7;
		break;
	case DIO_CHANNEL_PC8:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_8;
		break;
	case DIO_CHANNEL_PC9:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_9;
		break;
	case DIO_CHANNEL_PC10:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_10;
		break;
	case DIO_CHANNEL_PC11:
		gpioPort = GPIOC;
		gpioPin = GPIO_Pin_11;
		break;
	case DIO_CHANNEL_PC12:
		gpioPort = GPIOC;
		gpioPin = GPIO_Pin_12;
		break;
	case DIO_CHANNEL_PC13:
		gpioPort = GPIOC;
		gpioPin = GPIO_Pin_13;
		break;
	case DIO_CHANNEL_PC14:
		gpioPort = GPIOC;
		gpioPin = GPIO_Pin_14;
		break;
	case DIO_CHANNEL_PC15:
		gpioPort = GPIOC;
		gpioPin = GPIO_Pin_15;
		break;
	default:
		break;
	}

	if (Level == STD_LOW)
	{
		GPIO_ResetBits(gpioPort, gpioPin);
	}
	else
	{
		GPIO_SetBits(gpioPort, gpioPin);
	}
}





Dio_LevelType Dio_ReadChannel(Dio_channel_type ChannelId)
{
	GPIO_TypeDef *gpioPort;
	uint16_t gpioPin;

	switch (ChannelId)
	{
	case DIO_CHANNEL_PA0:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_0;
		break;
	case DIO_CHANNEL_PA1:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_1;
		break;

	case DIO_CHANNEL_PA2:
		gpioPort = GPIOA;
		gpioPin = GPIO_Pin_2;
		break;
	
	case DIO_CHANNEL_PB8:
		gpioPort = GPIOB;
		gpioPin = GPIO_Pin_8;
		break;

	case DIO_CHANNEL_PC13:
		gpioPort = GPIOC;
		gpioPin = GPIO_Pin_13;
		break;

	default:
		break;
	}

	if (GPIO_ReadInputDataBit(gpioPort, gpioPin) == 0)
	{
		return STD_LOW;
	}
	else
	{
		return STD_HIGH;
	}
}
