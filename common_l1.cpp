/// @file L1-specific utility functions

#include "common.h"

void gpio_defaults(GPIO_InitTypeDef *GPIO_InitStructure, GPIOMode_TypeDef mode)
{
    GPIO_StructInit(GPIO_InitStructure); // 400KHz
    if( mode == MODE_ANALOG)
        GPIO_InitStructure->GPIO_OType = GPIO_OType_OD; // open drain mode
    else
        GPIO_InitStructure->GPIO_OType = GPIO_OType_PP; // push/pull mode
    GPIO_InitStructure->GPIO_PuPd = GPIO_PuPd_NOPULL; // pull up, down or leave floating
    GPIO_InitStructure->GPIO_Mode = mode;
}


adc_init_t::adc_init_t(uint32_t trigger, uint8_t channel_count)
{
    ADC_StructInit(&init);

    init.ADC_ScanConvMode = ENABLE;
    init.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    init.ADC_ExternalTrigConv = trigger;
    init.ADC_NbrOfConversion = channel_count;
}

