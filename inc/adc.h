#ifndef ADC_H
#define ADC_H

#include "common.h"
#include "bus.h"
#include "pin.h"

/**
    @class AnalogInX
    @brief ADC device

    Possible template parameters APB1 or APB2 and their corresponding values
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
*/
template<typename T>
class AnalogInX: public Device<T>
{
public:
    /// Default specialized constructor
    AnalogInX(T pid);
    /// Starts conversion
    virtual void start();
    /// Stops conversion
    virtual void stop();
    /// Read 16 bits of the ADC data port
    virtual uint16_t read();
    /// Destruct and deinit ADC resources
    virtual ~AnalogInX();
    /// Interrupt handler
    static void interrupt();
    //static AnalogInX* adc1;
protected:
    /// ADC handle structure. Declared in standard peripheral library.
    ADC_TypeDef *_base = nullptr;
    ADC_InitTypeDef _init{
                        ADC_Mode_Independent,       //ADC_Mode
                        DISABLE,                    //ADC_ScanConvMode
                        DISABLE,                    //ADC_ContinuousConvMode
                        ADC_ExternalTrigConv_None,  //ADC_ExternalTrigConv
                        ADC_DataAlign_Right,        //ADC_DataAlign
                        1};                         //ADC_NbrOfChannel

};

using AnalogIn=AnalogInX<APB2>;


#endif // ADC_H
