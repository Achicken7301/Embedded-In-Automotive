#include "main.h"


uint8_t receivedByte = 0;

int main(void)
{
	SPIx_Init();
	DelayInit();
	while (1)
	{
		// Enable slave
		SPIx_EnableSlave();
		receivedByte = SPIx_Transfer(0x77); // 0x77 119 01110111
		
		// Disable slave
		SPIx_DisableSlave();
		DelayMs(2000/8);
	}
}
