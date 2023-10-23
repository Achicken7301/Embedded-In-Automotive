#include "main.h"

int main(void)
{
	softUART_TransmitInit();
	DelayInit();
	uint8_t data = 'a';
	while (1)
	{
		UART_writeByte(data);
		data++;
		DelayMs(2000);
	}
}

/**
*	LSB, no parity, 1stopbit
*/
void UART_writeByte(uint8_t data)
{
	// send start bit
	GPIO_ResetBits(GPIOB, TX_PIN);
	DelayMs(Tfull);
	uint8_t output;
	// Send data
	for(int i = 0; i < 8; i++){
		output = (data >> i) & 1;
		(output != 0) ? GPIO_SetBits(GPIOB, TX_PIN) : GPIO_ResetBits(GPIOB, TX_PIN);
		DelayMs(Tfull);
	}
	
	// stop bit
	GPIO_SetBits(GPIOB, TX_PIN); 
	DelayMs(Tfull);
}


void softUART_TransmitInit()
{
	// Enable APB CLock PORT B
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// GPIO config Tx
	GPIO_InitTypeDef Tx = {
		.GPIO_Mode = GPIO_Mode_Out_PP,
		.GPIO_Pin = TX_PIN,
		.GPIO_Speed = GPIO_Speed_2MHz
	};
	
	// GPIO config Rx
	GPIO_InitTypeDef Rx = {
		.GPIO_Mode = GPIO_Mode_IPU,
		.GPIO_Pin = RX_PIN,
		.GPIO_Speed = GPIO_Speed_2MHz
	};
	
	GPIO_Init(GPIOB, &Tx);
	GPIO_Init(GPIOB, &Rx);
	
	GPIO_SetBits(GPIOB, TX_PIN);
}
