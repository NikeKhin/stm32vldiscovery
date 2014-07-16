/// @file L1-specific utility functions

#include "common.h"

void gpio_defaults(GPIO_InitTypeDef *GPIO_InitStructure, GPIOMode_TypeDef mode)
{
    GPIO_StructInit(GPIO_InitStructure);
    GPIO_InitStructure->GPIO_Mode = mode;
}


