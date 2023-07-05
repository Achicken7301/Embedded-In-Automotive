#include "led.h"

uint8_t status = INIT_MODE1;
uint16_t duration = 250;
uint8_t index = 0;

uint16_t led_arr[NO_OF_LED] = {DIO_CHANNEL_PB12, DIO_CHANNEL_PB13, DIO_CHANNEL_PB14, DIO_CHANNEL_PB15, DIO_CHANNEL_PA8};

/**
 * @brief turn all leds off
 *
 */
void off_led()
{
	for (uint16_t i = 0; i < NO_OF_LED; i++)
	{
		Dio_WriteChannel(led_arr[i], STD_HIGH);
	}
}

void fsm_led_mode_1()
{
	switch (status)
	{
	case INIT_MODE1:
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = LED1_MODE1;
		}

		for (uint16_t i = 0; i < NO_OF_LED; i++)
		{
			Dio_WriteChannel(led_arr[i], STD_HIGH);
		}

		break;
	case LED1_MODE1:
		Dio_WriteChannel(led_arr[0], STD_LOW);

		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE2;
		}

		if (timer_flag == 1)
		{
			setTimer(duration);
			status = LED2_MODE1;
		}
		break;

	case LED2_MODE1:
		Dio_WriteChannel(led_arr[1], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE2;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = LED3_MODE1;
		}
		break;
	case LED3_MODE1:
		Dio_WriteChannel(led_arr[2], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE2;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = LED4_MODE1;
		}
		break;
	case LED4_MODE1:
		Dio_WriteChannel(led_arr[3], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE2;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = LED5_MODE1;
		}
		break;
	case LED5_MODE1:
		Dio_WriteChannel(led_arr[4], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE2;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = INIT_MODE1;
		}
		break;
	default:
		break;
	}
}

void fsm_led_mode_2()
{
	switch (status)
	{
	case INIT_MODE2:
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = LED1_MODE2;
		}
		off_led();
		Dio_WriteChannel(led_arr[0], STD_LOW);

		break;
	case LED1_MODE2:
		off_led();
		Dio_WriteChannel(led_arr[1], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE1;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = LED2_MODE2;
		}
		break;

	case LED2_MODE2:
		off_led();
		Dio_WriteChannel(led_arr[2], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE1;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);

			status = LED3_MODE2;
		}
		break;
	case LED3_MODE2:
		off_led();
		Dio_WriteChannel(led_arr[3], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE1;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);

			status = LED4_MODE2;
		}
		break;
	case LED4_MODE2:
		off_led();
		Dio_WriteChannel(led_arr[4], STD_LOW);
		// button pressed
		if (isBtnPress())
		{
			status = INIT_MODE1;
		}
		if (timer_flag == 1)
		{
			setTimer(duration);
			status = INIT_MODE2;
		}
		break;
	default:
		break;
	}
}