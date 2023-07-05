#include "Dio.h"
#include "stm32f10x.h"

static void initPort(GPIO_InitTypeDef *gpio, Dio_Port *port)
{
	switch (*port)
	{
	case Dio_PortA:
		GPIO_Init(GPIOA, gpio);
		break;
	case Dio_PortB:
		GPIO_Init(GPIOB, gpio);
		break;
	case Dio_PortC:
		GPIO_Init(GPIOC, gpio);
		break;
	default:
		break;
	}
}

static void enablePortClock(GPIO_InitTypeDef *gpio, Dio_Port *port)
{
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

static void pinSelect(GPIO_InitTypeDef *gpio, Dio_Pin *pin)
{
	switch (*pin)
	{
	case Dio_Pin_0:
		gpio->GPIO_Pin = GPIO_Pin_0;
		break;
	case Dio_Pin_1:
		gpio->GPIO_Pin = GPIO_Pin_1;
		break;
	case Dio_Pin_2:
		gpio->GPIO_Pin = GPIO_Pin_2;
		break;
	case Dio_Pin_3:
		gpio->GPIO_Pin = GPIO_Pin_3;
		break;
	case Dio_Pin_4:
		gpio->GPIO_Pin = GPIO_Pin_4;
		break;
	case Dio_Pin_5:
		gpio->GPIO_Pin = GPIO_Pin_5;
		break;
	case Dio_Pin_6:
		gpio->GPIO_Pin = GPIO_Pin_6;
		break;
	case Dio_Pin_7:
		gpio->GPIO_Pin = GPIO_Pin_7;
		break;
	case Dio_Pin_8:
		gpio->GPIO_Pin = GPIO_Pin_8;
		break;
	case Dio_Pin_9:
		gpio->GPIO_Pin = GPIO_Pin_9;
		break;
	case Dio_Pin_10:
		gpio->GPIO_Pin = GPIO_Pin_10;
		break;
	case Dio_Pin_11:
		gpio->GPIO_Pin = GPIO_Pin_11;
		break;
	case Dio_Pin_12:
		gpio->GPIO_Pin = GPIO_Pin_12;
		break;
	case Dio_Pin_13:
		gpio->GPIO_Pin = GPIO_Pin_13;
		break;
	case Dio_Pin_14:
		gpio->GPIO_Pin = GPIO_Pin_14;
		break;
	case Dio_Pin_15:
		gpio->GPIO_Pin = GPIO_Pin_15;
		break;
	}
}

void pinMode(Dio_Port port, Dio_Pin pin, GPIOMode_TypeDef type)
{
	GPIO_InitTypeDef gpio;
	gpio.GPIO_Mode = type;
	gpio.GPIO_Speed = GPIO_Speed_2MHz;

	// each type set clock and seperate port and pin
	switch (type)
	{
	case GPIO_Mode_IPU: // PinMode INPUT PUllUP
		pinSelect(&gpio, &pin);
		initPort(&gpio, &port);
		break;
	case GPIO_Mode_Out_PP: // OUTPUT - PP
		pinSelect(&gpio, &pin);
		enablePortClock(&gpio, &port);
		break;
	case GPIO_Mode_IN_FLOATING: // OUTPUT - PP
		pinSelect(&gpio, &pin);
	initPort(&gpio, &port);
		//enablePortClock(&gpio, &port);
		break;
	default:
		break;
	}
}

uint16_t gpioPIN(Dio_Pin *pin)
{
	switch (*pin)
	{
	case Dio_Pin_0:
		return GPIO_Pin_0;
		break;
	case Dio_Pin_1:
		return GPIO_Pin_1;
		break;
	case Dio_Pin_2:
		return GPIO_Pin_2;
		break;
	case Dio_Pin_3:
		return GPIO_Pin_3;
		break;
	case Dio_Pin_4:
		return GPIO_Pin_4;
		break;
	case Dio_Pin_5:
		return GPIO_Pin_5;
		break;
	case Dio_Pin_6:
		return GPIO_Pin_6;
		break;
	case Dio_Pin_7:
		return GPIO_Pin_7;
		break;
	case Dio_Pin_8:
		return GPIO_Pin_8;
		break;
	case Dio_Pin_9:
		return GPIO_Pin_9;
		break;
	case Dio_Pin_10:
		return GPIO_Pin_10;
		break;
	case Dio_Pin_11:
		return GPIO_Pin_11;
		break;
	case Dio_Pin_12:
		return GPIO_Pin_12;
		break;
	case Dio_Pin_13:
		return GPIO_Pin_13;
		break;
	case Dio_Pin_14:
		return GPIO_Pin_14;
		break;
	case Dio_Pin_15:
		return GPIO_Pin_15;
		break;
	}
}

void Dio_WriteChannel(Dio_Port port, Dio_Pin pin, Dio_LevelType Level)
{
	GPIO_TypeDef *gpioPort;
	uint16_t gpioPin;
	switch (port)
	{
	case Dio_PortA:
		gpioPort = GPIOA;
		gpioPin = gpioPIN(&pin);
		break;

	case Dio_PortB:
		gpioPort = GPIOB;
		gpioPin = gpioPIN(&pin);
		break;

	case Dio_PortC:
		gpioPort = GPIOC;
		gpioPin = gpioPIN(&pin);
		break;

	default:
		break;
	}
	
	(Level == STD_LOW) ? GPIO_ResetBits(gpioPort, gpioPin) : GPIO_SetBits(gpioPort, gpioPin);
}

/**
 * @brief Read pin's State.
 * 
 * @param port 
 * @param pin 
 * @return Dio_LevelType 
 */
Dio_LevelType Dio_ReadChannel(Dio_Port port, Dio_Pin pin)
{
	GPIO_TypeDef *gpioPort;
	uint16_t gpioPin;

	switch (port)
	{
	case Dio_PortA:
		gpioPort = GPIOA;
		gpioPin = gpioPIN(&pin);
		break;
	case Dio_PortB:
		gpioPort = GPIOB;
		gpioPin = gpioPIN(&pin);
		break;

	case Dio_PortC:
		gpioPort = GPIOC;
		gpioPin = gpioPIN(&pin);
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
