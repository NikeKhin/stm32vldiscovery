#ifndef ADC_H
#define ADC_H

#include "common.h"
#include "bus.h"
#include "pin.h"

/**
    @class Analog
    @brief ADC device

    Possible template parameters APB1 or APB2 and their corresponding values
    @param T - the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
    @param pid - peripheral ADC device identifier (e.g. APB2::adc1)
*/
template<typename T, T pid>
class Analog: public Device<T>
{
public:
    /// Default specialized constructor
    Analog();

    virtual void start() = 0;
    virtual void stop() = 0;

    /// Read 16 bits of the
    uint16_t read(){
        return 0;
    }
protected:
    /// ADC handle structure. Declared in standard peripheral library.
    ADC_TypeDef *_base = nullptr;
};

/**
    Specific ADC names
*/
using Analog1 = Analog<APB2, APB2::adc1>;
//using Analog2 = Analog<APB2, APB2::adc2>;



/**
    @class AnalogIn
    @brief ADC in single-conversion mode

    Possible template parameters are Analog1...Analog2 (see type aliasing above)
    @param T - the type alias for the specific ADC device (e.g. Analog1)
*/
template<typename T>
class AnalogIn: public T
{
public:
    AnalogIn(){
        ADC_InitTypeDef ADC_InitStructure;
        ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
        ADC_InitStructure.ADC_ScanConvMode = DISABLE;
        ADC_InitStructure.ADC_ContinuousConvMode = ENABLE; //DISABLE for event
        ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; // ADC_ExternalTrigConv_T3_TRGO;
        ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
        ADC_InitStructure.ADC_NbrOfChannel = 1;
        ADC_Init(ADC1 , &ADC_InitStructure);

        // Configure ADC_IN6
        //ADC_RegularChannelConfig(ADC1 , ADC_Channel_6 , 1,,!ADC_SampleTime_55Cycles5);
        // Enable ADC
        //ADC_Cmd(ADC1 , ENABLE);

        // Check the end of ADC1 reset calibration register
        //while(ADC_GetResetCalibrationStatus(ADC1));
        // Start ADC1 calibration
        //ADC_StartCalibration(ADC1);
        // Check the end of ADC1 calibration
        //while(ADC_GetCalibrationStatus(ADC1));


        //ADC_RegularChannelConfig(ADC1 , ADC_Channel_6 , 1, ADC_SampleTime_55Cycles5);
        //ADC_ITConfig(ADC1 , ADC_IT_EOC , ENABLE);
        //ADC_ExternalTrigConvCmd(ADC1 , ENABLE);
        //ADC_Cmd(ADC1 , ENABLE);

        //void ADC1_IRQHandler(void)
        //{
        // read ADC DR and set LED accordingly
        //ADC_ClearITPendingBit(ADC1 , ADC_IT_EOC);
        //}

    }
};



#endif // ADC_H
