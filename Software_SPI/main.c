#include "main.h"

/**
 * @brief Every Interupt, system call this function? Dont know why,
 * but can be modified in startup code.
 *
 */
void TIM2_IRQHandler()
{
	/* Checks whether the TIM2 interrupt has occurred or not*/
	if (TIM_GetITStatus(TIM2, TIM_IT_Update))
	{
		timerRun();
		/*Clears the TIM2 interrupt pending bit*/
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
unsigned int count = 0;
uint8_t rev;


int main(void)
{
	// setup timer2
	TIM2_INT_Init();
	DelayInit();

	// Setup spi Pin
	SoftSPI_InitPin spi_pin;

	spi_pin.SCK.port = Dio_PortA;
	spi_pin.SCK.pin_number = Dio_Pin_5;

	spi_pin.SS.port = Dio_PortA;
	spi_pin.SS.pin_number = Dio_Pin_4;

	spi_pin.MISO.port = Dio_PortA;
	spi_pin.MISO.pin_number = Dio_Pin_6;

	spi_pin.MOSI.port = Dio_PortA;
	spi_pin.MOSI.pin_number = Dio_Pin_7;

	spiInit(&spi_pin);
	

	uint8_t send_data = 0xF0; // F0 240 11110000
	while (1)
	{
		SPI_Start(&spi_pin);
		rev = SPI_transfer(&spi_pin, send_data);
		SPI_End(&spi_pin);
		DelayMs(2000);
	}
}
