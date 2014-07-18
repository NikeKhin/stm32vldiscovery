/// @file L1-specific utility functions

#include "common.h"
#include "tim.h"

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


adc_init_t::adc_init_t(adc_trigger_t trigger, uint8_t channel_count)
{
    ADC_StructInit(&init);

    init.ADC_ScanConvMode = ENABLE;
    init.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    init.ADC_ExternalTrigConv = trigger;
    init.ADC_NbrOfConversion = channel_count;
}

adc_trigger_t::adc_trigger_t():trigger{0xFFFFFFFF}{
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

void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState){};
void ADC_ResetCalibration(ADC_TypeDef* ADCx){};
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx){return RESET;};
void ADC_StartCalibration(ADC_TypeDef* ADCx){};
FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx){return RESET;};
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState){};
void RCC_ADCCLKConfig(uint32_t RCC_PCLK2){};

