#ifndef __SOFTWARE_I2C__
#define __SOFTWARE_I2C__

#include "Dio.h"
#include "delay.h"

#define Tfull 100*1000
#define Thalf Tfull/2

typedef struct
{
	Dio_Port port;
	Dio_Pin pin_number;
} Soft_i2cPin;

typedef struct SoftI2c_InitPin
{
	Soft_i2cPin SDA;
	Soft_i2cPin SCL;
	
	uint8_t (*send)(struct SoftI2c_InitPin *i2c_pin, uint8_t slave_address, uint8_t data);
} SoftI2c_InitPin;

void i2cInit(SoftI2c_InitPin *i2c_pin);
#endif