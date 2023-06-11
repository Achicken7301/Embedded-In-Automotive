#include "main.h"


void TIM2_IRQHandler()
{
	/* Checks whether the TIM2 interrupt has occurred or not*/
	if (TIM_GetITStatus(TIM2, TIM_IT_Update))
	{
		timerRun();
		read_buttons();
		/*Clears the TIM2 interrupt pending bit*/
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}


int main(void)
{
	// setup timer2
	TIM2_INT_Init();
	
	// setup output for led_pin
	for(uint16_t i = 0; i < NO_OF_LED; i++){
		pinConfig(led_arr[i], GPIO_Mode_Out_PP);
	}
	
	// buttons config
	GPIO_InitTypeDef btn;
	btn.GPIO_Mode = GPIO_Mode_IPU;
	btn.GPIO_Pin = GPIO_Pin_8;
	btn.GPIO_Speed = GPIO_Speed_2MHz;
	
	GPIO_Init(GPIOB, &btn);
	
	setTimer(1000);
	
	for(uint16_t i = 0; i < NO_OF_LED; i++){
		Dio_WriteChannel(led_arr[i], STD_HIGH);
	}
	
	while (1)
	{
		fsm_led_mode_1();
		fsm_led_mode_2();
	}
}
