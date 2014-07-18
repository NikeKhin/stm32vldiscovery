#include "adc.h"

/**
    @brief Array of all ADC's ever constructed
*/
Analog* Analog::adc[] = {nullptr};

/**
    @brief Empty constructor. No ADC attached to APB1 yet
*/
Analog::Analog(APB1 id):
    Device{id}
{
}

/**
    @brief ADC, connected to APB2 initialization
    @param id ADC device identificator
*/
Analog::Analog(APB2 id):
    Device{id},
    _base{ adc_base(id,apb2_adcs) }
{
    // ADCCLK should be less than 14MHz. Here ADCCLK = PCLK2/2 = 24/2 = 12MHz
    // Divider options: RCC_PCLK2_Div2,RCC_PCLK2_Div4,RCC_PCLK2_Div6,RCC_PCLK2_Div8
    // TODO: To be done once for all ADCs.
    RCC_ADCCLKConfig(RCC_PCLK2_Div2);
    // Register this for IRQ handling
    adc[0] = this;
    // ADC default configuration
    //ADC_StructInit(&_init);
    //load structure values to control and status registers
    //ADC_Init(_base, &_init);
    // configure NVIC: list all necessary interrupts here
    _irq(ADC1_IRQn);
}


/**
    @brief Starts conversion engine. Can use external trigger events or software event
*/
void Analog::start(const Timer * const tim)
{
/* Possible trigger events for F1
ADC_ExternalTrigConv_None
ADC_ExternalTrigConv_T1_CC1
ADC_ExternalTrigConv_T1_CC2
ADC_ExternalTrigConv_T1_CC3
ADC_ExternalTrigConv_T2_CC2
ADC_ExternalTrigConv_T3_TRGO
ADC_ExternalTrigConv_T4_CC4
ADC_ExternalTrigConv_Ext_IT11_TIM8_TRGO

    Possible trigger events for L1
ADC_ExternalTrigConv_T2_CC3
ADC_ExternalTrigConv_T2_CC2
ADC_ExternalTrigConv_T2_TRGO
ADC_ExternalTrigConv_T3_CC1
ADC_ExternalTrigConv_T3_CC3
ADC_ExternalTrigConv_T3_TRGO
ADC_ExternalTrigConv_T4_CC4
ADC_ExternalTrigConv_T4_TRGO
ADC_ExternalTrigConv_T6_TRGO
ADC_ExternalTrigConv_T9_CC2
ADC_ExternalTrigConv_T9_TRGO
ADC_ExternalTrigConv_Ext_IT11

ADC_ExternalTrigConvEdge_None
ADC_ExternalTrigConvEdge_Rising
ADC_ExternalTrigConvEdge_Falling
ADC_ExternalTrigConvEdge_RisingFalling

*/


    adc_trigger_t trigger;// = ADC_ExternalTrigConv_None; //L1: ADC_ExternalTrigConvEdge_None
    if(tim!= nullptr)
        trigger = tim;

    adc_init_t config(trigger,channel_count);

    // Base initialization procedure
    ADC_Init(_base, &config.init);
    // Enable conversion through external trigger
    if(trigger){
        ADC_ExternalTrigConvCmd(_base, ENABLE);
    }
    // ADC_IT_EOC - end of conversion IRQ
    // ADC_IT_AWD - analog watchdog IRQ
    // ADC_IT_JEOC - end of injected conversion IRQ
    ADC_ITConfig(_base , ADC_IT_EOC , ENABLE);
    // Enable ADC
    //TODO: enabling really before calibration? Then IRQ enabling probably shoud go after calibration
    ADC_Cmd(_base, ENABLE);
    //Enable ADC1 reset calibration register
    ADC_ResetCalibration(_base);
    //Check the end of ADC1 reset calibration register
    while(ADC_GetResetCalibrationStatus(_base));
    //Start ADC1 calibration
    ADC_StartCalibration(_base);
    //Check the end of ADC1 calibration
    while(ADC_GetCalibrationStatus(_base));
    //Iterate through regular channel group starting with the first
    ch = channel_list.begin();
}

/**
    @brief Stops conversion engine.
*/
void Analog::stop()
{
    // Disable external triggering
    ADC_ExternalTrigConvCmd(_base, DISABLE);
    //Disable the interrupt
    ADC_ITConfig(_base , ADC_IT_EOC , DISABLE);
    //Disable the ADC
    ADC_Cmd(_base, DISABLE);
}

/**
    @brief Reads conversion value.
    @returns The value
*/
uint16_t Analog::read()
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

/**
    @brief Stops engine and deallocates resources.
*/
Analog::~Analog()
{
    // Excessive but better stop if not be stopped by the next deinit/reset calls.
    stop();
    ADC_DeInit(_base);
}

/**
    @brief End Of Conversion handler. All physical staff was left in IRQ handler
*/
void Analog::end_of_conversion()
{
    if (ch == channel_list.end())
        ch = channel_list.begin();
    (*ch)->write(ADC_GetConversionValue(_base));
    ++ch;
}

/**
    @brief Extern C IRQ handler for ADC1 with all necessary physical bit manipulation
*/
void ADC1_IRQHandler(void)
{
    // Check if it is end of conversion
    if (ADC_GetITStatus(ADC1, ADC_IT_EOC)) {
        // Process EOC interrupt
        Analog::adc[0]->end_of_conversion();
        // Clear specific IRQ pending bit for this specific ADC1_IRQ
        ADC_ClearITPendingBit(ADC1, ADC_IT_EOC);
    }
    // Check if it is end of injected conversion
    else if(ADC_GetITStatus(ADC1, ADC_IT_JEOC)){
        // Process EOC interrupt
        //Analog::adc[0]->end_of_jconversion();
        // Clear specific IRQ pending bit for this specific ADC1_IRQ
        ADC_ClearITPendingBit(ADC1, ADC_IT_JEOC);
    }
    // Check if it is end of injected conversion
    else if(ADC_GetITStatus(ADC1, ADC_IT_AWD)){
        // Process EOC interrupt
        //Analog::adc[0]->end_of_jconversion();
        // Clear specific IRQ pending bit for this specific ADC1_IRQ
        ADC_ClearITPendingBit(ADC1, ADC_IT_AWD);
    }
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

PA0 ADC1_IN0
PA1 ADC1_IN1
PA2 ADC1_IN2
PA3 ADC1_IN3
PA4 ADC1_IN4
PA5 ADC1_IN5
PA6 ADC1_IN6
PA7 ADC1_IN7
PB0 ADC1_IN8
PB1 ADC1_IN9
PC0 ADC1_IN10
PC1 ADC1_IN11
PC2 ADC1_IN12
PC3 ADC1_IN13
PC4 ADC1_IN14
PC5 ADC1_IN15

http://www.keil.com/forum/18722/
*/
