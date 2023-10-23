#include "main.h"

uint8_t rev = 0x00;

int main(void)
{
	softUART_ReceiveInit();
	DelayInit();
	
	
	while (1)
	{
		rev = UART_readByte();
		// DelayMs(1000);
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

uint8_t UART_readByte()
{
	uint8_t byte_in = 0x00;
	uint8_t res;
	uint8_t input;
	
	// Wait for Rx is LOW
	while(GPIO_ReadInputDataBit(GPIOA, RX_PIN) == Bit_SET);
	
	// Wait for Thalf
	DelayMs(Thalf + Tfull);
	
	// Start readbit
	for(int i = 0; i < 8; i++)
	{
		res = GPIO_ReadInputDataBit(GPIOA, RX_PIN);
		
		(res == 1) ? GPIO_SetBits(GPIOC, GPIO_Pin_13) : GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		
		res = res << i;
		byte_in = byte_in | res;
		DelayMs(Tfull);
	}
	
	// stopbit	
	input = GPIO_ReadInputDataBit(GPIOA, RX_PIN);
	if(input == Bit_RESET) {
		return 0;
	}
	
	return byte_in;
}

void softUART_ReceiveInit()
{
	// Enable APB CLock PORT A
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	// GPIO config Tx
	GPIO_InitTypeDef Tx = {
		.GPIO_Mode = GPIO_Mode_Out_PP,
		.GPIO_Pin = TX_PIN,
		.GPIO_Speed = GPIO_Speed_2MHz
	};
	
	
	// GPIO config BUILTIN_LED
	GPIO_InitTypeDef BUILTIN_LED = {
		.GPIO_Mode = GPIO_Mode_Out_PP,
		.GPIO_Pin = GPIO_Pin_13,
		.GPIO_Speed = GPIO_Speed_2MHz
	};
	
	// GPIO config Rx
	GPIO_InitTypeDef Rx = {
		.GPIO_Mode = GPIO_Mode_IN_FLOATING,
		.GPIO_Pin = RX_PIN,
		.GPIO_Speed = GPIO_Speed_2MHz
	};
	
	GPIO_Init(GPIOC, &BUILTIN_LED);
	GPIO_Init(GPIOA, &Tx);
	GPIO_Init(GPIOA, &Rx);
	
	//GPIO_SetBits(GPIOA, TX_PIN);
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


void timerInit(){
	
}
