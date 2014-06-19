#include "adc.h"


ADConverter1::ADConverter1():/*bus(Bus2()),*/base(ADC1)
{
    //RCC_ADCCLKConfig(RCC_PCLK2_Div2);
    // Clock the bus
    //bus.enable(PeripheralID::adc1);
    // Setup pin
    //pin.setupSlowInAnalog();
    //ADC configuration
    ADC_InitTypeDef ADC_InitStructure;
    //select independent conversion mode (single)
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    //convert single channel only
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    //convert one time
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    //select no external triggering
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    //right 12-bit data alignment in ADC data register
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    //single channel conversion
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    //load structure values to control and status registers
    ADC_Init(base, &ADC_InitStructure);
}


void ADConverter1::start()
{
    //wake up temperature sensor
    ADC_TempSensorVrefintCmd(ENABLE);
    //ADC1 channel16 configuration
    //we select 41.5 cycles conversion for channel16
    //and rank=1 which doesn't matter in single mode
    ADC_RegularChannelConfig(base, ADC_Channel_16, 1, ADC_SampleTime_41Cycles5);
    //Enable ADC1
    ADC_Cmd(base, ENABLE);
    //Enable ADC1 reset calibration register
    ADC_ResetCalibration(base);
    //Check the end of ADC1 reset calibration register
    while(ADC_GetResetCalibrationStatus(base));
    //Start ADC1 calibration
    ADC_StartCalibration(base);
    //Check the end of ADC1 calibration
    while(ADC_GetCalibrationStatus(base));
}

void ADConverter1::stop()
{
    //Disable the ADC
    ADC_Cmd(base, DISABLE);
}

uint16_t ADConverter1::read()
{
    uint16_t value;
    //start the ADC Software Conversion
    ADC_SoftwareStartConvCmd(base, ENABLE);
    //wait for conversion complete
    while(!ADC_GetFlagStatus(base, ADC_FLAG_EOC)){}
    //read ADC value
    value=ADC_GetConversionValue(base);
    //clear EOC flag
    ADC_ClearFlag(base, ADC_FLAG_EOC);
    //return the result
    return value;
}

ADConverter1::~ADConverter1()
{
    ADC_DeInit(base);
}

