#include "main.h"

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

int main(void)
{
	pinConfig(DIO_CHANNEL_PC13, GPIO_Mode_Out_PP);
	pinConfig(DIO_CHANNEL_PB12, GPIO_Mode_Out_PP);
	setTimer(1000);
	TIM2_INT_Init();

	while (1)
	{
		if (timer_flag == 1)
		{
			setTimer(1000);
			GPIOC->ODR ^= GPIO_Pin_13;
			GPIOB->ODR ^= GPIO_Pin_12;
		}
	}
}
