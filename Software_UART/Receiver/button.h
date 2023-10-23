#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "stm32f10x.h"
#include "Dio.h"

void read_buttons();
int isBtnPress();
extern int button_flag;

#endif