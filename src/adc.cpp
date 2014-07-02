#include "adc.h"

template<>
AnalogInX<APB2>::AnalogInX(APB2 id):
    Device{APB2::adc1},
    _base{ADC1},
    _init{
        ADC_Mode_Independent,       //ADC_Mode, select independent conversion mode (single)
        DISABLE,                    //ADC_ScanConvMode, convert single channel only
        DISABLE,                    //ADC_ContinuousConvMode, convert one time
        ADC_ExternalTrigConv_None,  //ADC_ExternalTrigConv, select no external triggering. ADC_ExternalTrigConv_T3_TRGO for timer event
        ADC_DataAlign_Right,        //ADC_DataAlign, right 12-bit data alignment in ADC data register
        1}                          //ADC_NbrOfChannel, single channel conversion

{
    //RCC_PCLK2_Div2
    //RCC_PCLK2_Div4
    //RCC_PCLK2_Div6
    //RCC_PCLK2_Div8
    //RCC_ADCCLKConfig(RCC_PCLK2_Div2);

    // Clock the bus
    //bus.enable(PeripheralID::adc1);
    // Setup pin
    //pin.setupSlowInAnalog();

    //ADC default configuration
    //void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);

    //AnalogInX::adc1 = this;
    //load structure values to control and status registers
    ADC_Init(_base, &_init);
}

/*
ADC_Mode:
ADC_Mode_Independent
ADC_Mode_RegInjecSimult
ADC_Mode_RegSimult_AlterTrig
ADC_Mode_InjecSimult_FastInterl
ADC_Mode_InjecSimult_SlowInterl
ADC_Mode_InjecSimult
ADC_Mode_RegSimult
ADC_Mode_FastInterl
ADC_Mode_SlowInterl
ADC_Mode_AlterTrig

ADC_ScanConvMode:
ENABLE || DISABLE

ADC_ContinuousConvMode
ENABLE || DISABLE

ADC_ExternalTrigConv:
For ADC1 and ADC2
ADC_ExternalTrigConv_T1_CC1
ADC_ExternalTrigConv_T1_CC2
ADC_ExternalTrigConv_T2_CC2
ADC_ExternalTrigConv_T3_TRGO
ADC_ExternalTrigConv_T4_CC4
ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO
For ADC1, ADC2 and ADC3
ADC_ExternalTrigConv_T1_CC3
ADC_ExternalTrigConv_None
For ADC3 only
ADC_ExternalTrigConv_T3_CC1
ADC_ExternalTrigConv_T2_CC3
ADC_ExternalTrigConv_T8_CC1
ADC_ExternalTrigConv_T8_TRGO
ADC_ExternalTrigConv_T5_CC1
ADC_ExternalTrigConv_T5_CC3


void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number);
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);

uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
uint32_t ADC_GetDualModeConversionValue(void);

void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);

ADC_Channel:
ADC_Channel_0...ADC_Channel_17
ADC_Channel_TempSensor=ADC_Channel_16
ADC_Channel_Vrefint=ADC_Channel_17

ADC_SampleTime:
ADC_SampleTime_1Cycles5
ADC_SampleTime_7Cycles5
ADC_SampleTime_13Cycles5
ADC_SampleTime_28Cycles5
ADC_SampleTime_41Cycles5
ADC_SampleTime_55Cycles5
ADC_SampleTime_71Cycles5
ADC_SampleTime_239Cycles5

*/



template<typename T>
void AnalogInX<T>::start()
{
    //wake up temperature sensor
    ADC_TempSensorVrefintCmd(ENABLE);
    //ADC channel16 () configuration
    //we select 41.5 cycles conversion for channel16
    //and rank=1 which doesn't matter in single mode
    ADC_RegularChannelConfig(_base, ADC_Channel_16, 1, ADC_SampleTime_41Cycles5);
    //Enable ADC
    ADC_Cmd(_base, ENABLE);

    //ADC_RegularChannelConfig(ADC1 , ADC_Channel_6 , 1, ADC_SampleTime_55Cycles5);
    // ADC_IT_EOC - end of conversion
    // ADC_IT_AWD -
    // ADC_IT_JEOC -
    //ADC_ITConfig(_base , ADC_IT_EOC , ENABLE);
    //ADC_ExternalTrigConvCmd(ADC1 , ENABLE);
    //ADC_Cmd(ADC1 , ENABLE);


    //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    //NVIC_InitTypeDef NVIC_InitStructure;
    //NVIC_InitStructure.NVIC_IRQChannel = ADC1_IRQn; // or ADC1_2_IRQn
    //NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    //NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    //NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    //NVIC_Init(&NVIC_InitStructure);


    //Enable ADC1 reset calibration register
    ADC_ResetCalibration(_base);
    //Check the end of ADC1 reset calibration register
    while(ADC_GetResetCalibrationStatus(_base));
    //Start ADC1 calibration
    ADC_StartCalibration(_base);
    //Check the end of ADC1 calibration
    while(ADC_GetCalibrationStatus(_base));
}

template<typename T>
void AnalogInX<T>::stop()
{
    //Disable the ADC
    ADC_Cmd(_base, DISABLE);
}

template<typename T>
uint16_t AnalogInX<T>::read()
{
    uint16_t value;
    //start the ADC Software Conversion
    ADC_SoftwareStartConvCmd(_base, ENABLE);
    //wait for conversion complete
    while(!ADC_GetFlagStatus(_base, ADC_FLAG_EOC)){}
    //read ADC value
    value=ADC_GetConversionValue(_base);
    //clear EOC flag
    ADC_ClearFlag(_base, ADC_FLAG_EOC);
    //return the result
    return value;
}

template<typename T>
AnalogInX<T>::~AnalogInX()
{
    // Excessive but better stop if not be stopped by the next deinit/reset calls.
    stop();
    ADC_DeInit(_base);
}

template<typename T>
void AnalogInX<T>::interrupt()
{
    uint16_t value = ADC_GetConversionValue(ADC1);
}


#ifdef __cplusplus
extern "C" {
#endif
void ADC1_IRQHandler(void)
{
    if (ADC_GetITStatus(ADC1, ADC_IT_EOC)) {
        // Process interrupt
        AnalogIn::interrupt();
        // Clear specific IRQ pending bit for this specific ADC1_IRQ
        ADC_ClearITPendingBit(ADC1 , ADC_IT_EOC);
    }
}
#ifdef __cplusplus
}
#endif
