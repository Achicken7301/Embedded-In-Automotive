# Brief note

## Cấu trúc

1. Application (ASW)
2. RTE (RTOS,...)
3. Base Software (BSW)
   1. Service Layer
   2. ECU Abstraction layer
   3. CCD
   4. MCAL
4. MCU

## Config GPIO

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

## Dio Channel

Setup pin mode (input or output, pull up or pull down)

Setup pin write output (high or low)

setup pin read

## Ngắt (Interrupt)

Program Counter (PC) là bộ đếm bước nhảy của vi điều khiển.

Stack pointer: đang chạy trong hàm main, xảy ra hàm ngắt, thì chương trình sẽ chuyển qua hàm ngắt để xử lý, lúc này địa chỉ của dòng lệnh cũ sẽ được lưu lại trong Stack Pointer, để sau khi chạy ngắt xong, chương trình lấy trong Stack Pointer này ra để chạy tiếp.

### Ngắt ngoài

là giá trị của chân vi điều khiển bị thay đổi. Có 4 chế độ ngắt trong các vi điều khiển:

 - LOW: chân của vi điều khiển từ cao xuống thấp -> ngắt
 - HIGH: chân của vi điều khiển từ thấp lên cao -> ngắt
 - RISING: khó giải thích quá ta.
 - FALLING

### Ngắt timer



### Ngắt truyền thông



## Software SPI

## Hardware SPI

## Software I2C

## Hardware I2C

# UART
Những thông tin cần lưu ý, tốc độ baudrate, bit chẳn lẽ. 

## BAUDRATE
là trong 1s truyền được bao nhiêu bit, từ đó tính được timer sử dụng để ngắt truyền data.


## bit chẳn lẽ 