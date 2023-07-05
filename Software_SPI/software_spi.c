#include "software_spi.h"

/**
 * @brief Clock Speed TFull = 1000us => 1ms
 *
 */
#define TFull 1000 
#define THalf TFull / 2

void spiInit(SoftSPI_InitPin *SPI_pin)
{
	// CLK, MOSI, SS - OUTPUT
	// MISO - INPUT
	pinMode(SPI_pin->SCK.port, SPI_pin->SCK.pin_number, GPIO_Mode_Out_PP);
	pinMode(SPI_pin->SS.port, SPI_pin->SS.pin_number, GPIO_Mode_Out_PP);
	pinMode(SPI_pin->MOSI.port, SPI_pin->MOSI.pin_number, GPIO_Mode_Out_PP);
	pinMode(SPI_pin->MISO.port, SPI_pin->MISO.pin_number, GPIO_Mode_IN_FLOATING);

	// CPOL, CPHA: 0, 0
	// SCK LOW
	Dio_WriteChannel(SPI_pin->SCK.port, SPI_pin->SCK.pin_number, STD_LOW);
	// SS HIGH
	Dio_WriteChannel(SPI_pin->SS.port, SPI_pin->SS.pin_number, STD_HIGH);
}

void SPI_Start(SoftSPI_InitPin *SPI_pin)
{
	Dio_WriteChannel(SPI_pin->SS.port, SPI_pin->SS.pin_number, STD_LOW);
}

/**
 * @brief End SPI communication by SS - HIGH, SCK - LOW
 * 
 * @param SPI_pin 
 */
void SPI_End(SoftSPI_InitPin *SPI_pin)
{
	Dio_WriteChannel(SPI_pin->SS.port, SPI_pin->SS.pin_number, STD_HIGH);
	Dio_WriteChannel(SPI_pin->SCK.port, SPI_pin->SCK.pin_number, STD_LOW);
}

/**
 * @brief Master sends data to slave
 *
 * @param byte_out
 * @return uint8_t
 */
uint8_t SPI_transfer(SoftSPI_InitPin *pin, uint8_t byte_out)
{
	uint8_t byte_in = 0;
	uint8_t ibit, res;

	for (ibit = 0x80; ibit > 0; ibit = ibit >> 1)
	{
		// res!=0 or res=0
		res = byte_out & ibit;
		
		(res != 0) ? Dio_WriteChannel(pin->MOSI.port, pin->MOSI.pin_number, STD_HIGH) : Dio_WriteChannel(pin->MOSI.port, pin->MOSI.pin_number, STD_LOW);

		// Start Clock
		DelayUs(THalf);
		Dio_WriteChannel(pin->SCK.port, pin->SCK.pin_number, STD_HIGH);

		// Read data from MISO, bit order LSB
		if (Dio_ReadChannel(pin->MISO.port, pin->MISO.pin_number))
		{
			byte_in |= ibit;
		}

		DelayUs(THalf);
		Dio_WriteChannel(pin->SCK.port, pin->SCK.pin_number, STD_LOW); // End 1 Clock
	}

	return byte_in;
}

