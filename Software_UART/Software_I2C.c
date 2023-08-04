#include "Software_I2C.h"

/**
 * @brief i2c start condition.
 *
 * @param i2c_pin
 */
static void beginI2C(SoftI2c_InitPin *i2c_pin)
{

	// SCK, SDA - OUTPUT
	pinMode(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, GPIO_Mode_Out_PP);
	pinMode(i2c_pin->SDA.port, i2c_pin->SCL.pin_number, GPIO_Mode_Out_PP);

	// START Transmit, SDA goes low before SCK
	Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_LOW);
	DelayUs(Thalf);
	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_LOW);
	DelayUs(Thalf);
}

static void clock_output(SoftI2c_InitPin *i2c_pin)
{
	DelayUs(Thalf);
	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_HIGH);
	DelayUs(Thalf);
	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_LOW);
}

/**
 * @brief STOP condition for i2c communication protocol
 *
 * @param i2c_pin
 * @param slave_address
 */
void endI2C(SoftI2c_InitPin *i2c_pin)
{
	Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_LOW);
	DelayUs(Thalf);
	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_HIGH);
	DelayUs(Thalf);
	Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_HIGH);
}

static uint8_t readACK(SoftI2c_InitPin *i2c_pin)
{
	uint8_t ACK;
	// Read ACK - clock 9th
	pinMode(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, GPIO_Mode_IN_FLOATING);
	DelayUs(Thalf);
	// create SCK pulse
	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_HIGH);
	// Read ACK
	ACK = Dio_ReadChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number);
	DelayUs(Thalf);

	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_LOW);
	pinMode(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, GPIO_Mode_Out_PP);
	DelayUs(Thalf);
	Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_HIGH);
	return ACK;
}

void writeByte(SoftI2c_InitPin *i2c_pin, uint8_t data)
{
	uint8_t res;
	for (uint8_t ibit = 0x80; ibit > 0; ibit = ibit >> 1)
	{
		res = data & ibit;
		(res != 0) ? Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_HIGH) : Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_LOW);

		// clock
		clock_output(i2c_pin);
	}
}

void writeI2C(SoftI2c_InitPin *i2c_pin, uint8_t slave_address, uint8_t data)
{
	uint8_t ACK;
	beginI2C(i2c_pin);
	writeByte(i2c_pin, (slave_address << 1));

	// read ACK
	// pinMode(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, GPIO_Mode_IPD);

	ACK = readACK(i2c_pin);
	// pinMode(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, GPIO_Mode_Out_PP);
	if (ACK == 0) // repeated start
	{
		Dio_WriteChannel(Dio_PortB, Dio_Pin_12, STD_LOW);
		writeByte(i2c_pin, data);
		ACK = readACK(i2c_pin);
		endI2C(i2c_pin);
	}
	else
	{
		endI2C(i2c_pin);
		Dio_WriteChannel(Dio_PortB, Dio_Pin_12, STD_HIGH);
	}

	// ideal state, SCK, SDA - HIGH
	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_HIGH);
	Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_HIGH);
}

/**
 * @brief Initiate i2c configuration & function pointer
 *
 * @param i2c_pin: address
 */
void i2cInit(SoftI2c_InitPin *i2c_pin)
{
	DelayInit();

	// SCK, SDA - OUTPUT
	pinMode(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, GPIO_Mode_Out_PP);
	pinMode(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, GPIO_Mode_Out_PP);

	// ACK pin
	pinMode(Dio_PortB, Dio_Pin_12, GPIO_Mode_Out_PP);

	// ideal state, SCK, SDA - HIGH
	Dio_WriteChannel(i2c_pin->SCL.port, i2c_pin->SCL.pin_number, STD_HIGH);
	Dio_WriteChannel(i2c_pin->SDA.port, i2c_pin->SDA.pin_number, STD_HIGH);

	i2c_pin->send = &writeI2C;
	DelayMs(10);
}
