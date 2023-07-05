#include "main.h"

int main(void)
{
	// setup timer2
	TIM2_INT_Init();
	DelayInit();

	// Setup i2c Pin
	SoftI2c_InitPin i2c_pin;
	
	i2c_pin.SCL.port = Dio_PortB;
	i2c_pin.SDA.port = Dio_PortB;
	
	i2c_pin.SCL.pin_number = Dio_Pin_6;
	i2c_pin.SDA.pin_number = Dio_Pin_7;
	
	uint8_t sendData = 0x77;
	uint8_t slaveAdd = 0x55;
	
	i2cInit(&i2c_pin);

	while (1)
	{	uint8_t data;
		i2c_pin.send(&i2c_pin, slaveAdd, sendData);
		DelayMs(5000);
	}
}
