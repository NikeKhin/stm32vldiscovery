/// @file F1-specific utility functions

#include "common.h"
#include "tim.h"

void gpio_defaults(GPIO_InitTypeDef *GPIO_InitStructure, GPIOMode_TypeDef mode)
{
    GPIO_StructInit(GPIO_InitStructure);
    GPIO_InitStructure->GPIO_Mode = mode;
}


adc_init_t::adc_init_t(adc_trigger_t trigger, uint8_t channel_count)
{
    ADC_StructInit(&init);
    init={
        ADC_Mode_Independent,        //ADC_Mode, select independent conversion mode (single or multiple)
        ENABLE,                      //ADC_ScanConvMode, convert single (disabled) or multiple (enabled) channel
        DISABLE,                     //ADC_ContinuousConvMode, convert one time
        trigger,                     //ADC_ExternalTrigConv, ADC_ExternalTrigConv_T3_TRGO for timer event. ADC_ExternalTrigConv_None selects no external triggering.
        ADC_DataAlign_Right,         //ADC_DataAlign, right 12-bit data alignment in ADC data register
        channel_count                //ADC_NbrOfChannel, single or multiple channel conversion
    };
}

adc_trigger_t::adc_trigger_t():trigger{ADC_ExternalTrigConv_None}{
}

adc_trigger_t::operator uint32_t(){
    return trigger;
}

adc_trigger_t::operator bool(){
    return (trigger==0xFFFFFFFF)?false:true;
}

adc_trigger_t& adc_trigger_t::operator=(const Timer* tim){
    trigger=tim->trigger();//ADC_ExternalTrigConv_T3_TRGO;
}
