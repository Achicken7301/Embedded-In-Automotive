#include "software_spi.h"

/**
 * @brief clock speed f = ... => T = 1000us
 *
 */
#define TFull 50000
#define THalf TFull / 2

void spiInit(SoftSPI_InitPin *SPI_pin)
{
	DelayInit();
	
	// CLK, MOSI, SS - OUTPUT
	// MISO - INPUT
	pinMode(SPI_pin->SCK.port, SPI_pin->SCK.pin_number, GPIO_Mode_Out_PP);
	pinMode(SPI_pin->SS.port, SPI_pin->SS.pin_number, GPIO_Mode_Out_PP);
	pinMode(SPI_pin->MOSI.port, SPI_pin->MOSI.pin_number, GPIO_Mode_Out_PP);
	pinMode(SPI_pin->MISO.port, SPI_pin->MISO.pin_number, GPIO_Mode_IPU);

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

void SPI_End(SoftSPI_InitPin *SPI_pin)
{
	Dio_WriteChannel(SPI_pin->SS.port, SPI_pin->SS.pin_number, STD_HIGH);
	Dio_WriteChannel(SPI_pin->SCK.port, SPI_pin->SCK.pin_number, STD_LOW);
}

/**
 * @brief Bit Order MSB
 *
 * @param byte_out
 * @return uint8_t
 */
uint8_t SPI_transfer(SoftSPI_InitPin *pin, uint8_t byte_out)
{
	uint8_t byte_in = 0x00;
	uint8_t ibit, res;

	for (ibit = 0x80; ibit > 0; ibit = ibit >> 1)
	{
		res = byte_out & ibit;
		// if (res != 0)
		// {
		// 	Dio_WriteChannel(pin->MOSI.port, pin->MOSI.pin_number, STD_HIGH);
		// }
		// else
		// {
		// 	Dio_WriteChannel(pin->MOSI.port, pin->MOSI.pin_number, STD_LOW);
		// }
		(res != 0) ? Dio_WriteChannel(pin->MOSI.port, pin->MOSI.pin_number, STD_HIGH) : Dio_WriteChannel(pin->MOSI.port, pin->MOSI.pin_number, STD_LOW);

		// Start 1/2 Clock
		DelayUs(THalf);
		Dio_WriteChannel(pin->SCK.port, pin->SCK.pin_number, STD_HIGH);

		// Read data from MISO, bit order LSB
		if (Dio_ReadChannel(pin->MISO.port, pin->MISO.pin_number))
		{
			byte_in |= ibit;
		}
		// Start 1/2 Clock left
		DelayUs(THalf);
		Dio_WriteChannel(pin->SCK.port, pin->SCK.pin_number, STD_LOW); // End 1 Clock
	}

	return byte_in;
}