#include "button.h"

int button_flag = 0;

void read_buttons()
{
	if (Dio_ReadChannel(DIO_CHANNEL_PB8) == 0)
	{
		button_flag = 1;
	}
}

int isBtnPress()
{
	if (button_flag == 1)
	{
		button_flag = 0;
		return 1;
	}

	return 0;
}