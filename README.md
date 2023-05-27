# Cấu trúc
1. Application (ASW)
2. RTE (RTOS,...)
3. Base Software (BSW)
   1. Service Layer
   2. ECU Abstraction layer
   3. CCD
   4. MCAL
4. MCU

# Config GPIO
```c
// Configure Clock Pulse for port GPIOC
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

GPIO_InitTypeDef gpio;

// Setup GPIO (more detail in beblow description)
gpio.GPIO_Pin = GPIO_Pin_13;
gpio.GPIO_Speed = GPIO_Speed_2MHz;
gpio.GPIO_Mode = GPIO_Mode_Out_PP; 

GPIO_Init(GPIOC, &gpio);
```

Source Code GPIO Init structure definition:
```c
/** 
  * @brief  GPIO Init structure definition  
  */

typedef struct
{
  uint16_t GPIO_Pin;             /*!< Specifies the GPIO pins to be configured.
                                      This parameter can be any value of @ref GPIO_pins_define */

  GPIOSpeed_TypeDef GPIO_Speed;  /*!< Specifies the speed for the selected pins.
                                      This parameter can be a value of @ref GPIOSpeed_TypeDef */

  GPIOMode_TypeDef GPIO_Mode;    /*!< Specifies the operating mode for the selected pins.
                                      This parameter can be a value of @ref GPIOMode_TypeDef */
}GPIO_InitTypeDef;

```