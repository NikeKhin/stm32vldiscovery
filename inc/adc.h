#ifndef ADC_H
#define ADC_H

#include "common.h"
#include "bus.h"
#include "pin.h"

/// ADC IRQ handler to get C-linkage
extern "C"
void ADC1_IRQHandler();

/**
    @class AnalogX
    @brief ADC device

    Possible template parameters APB1 or APB2 and their corresponding values
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
    This parameter can be one of the following values:
      @arg APB1
      @arg APB2
*/
template<typename T>
class AnalogX: public Device<T>
{
public:
    /// Default specialized constructor
    AnalogX(T id);
    /// Starts conversion
    virtual void start(APin pin);
    /// Stops conversion
    virtual void stop();
    /// Read 16 bits of the ADC data port
    virtual uint16_t read();
    /// Destruct and deinit ADC resources
    virtual ~AnalogX();
    /// Registered ADC's
    static AnalogX<T>* adc[];
protected:
    /// ADC handle structure. Declared in standard peripheral library. E.g. ADC1, ADC2...
    ADC_TypeDef *_base = nullptr;
    /// ADC initialization structure.
    ADC_InitTypeDef _init{
                        ADC_Mode_Independent,       //ADC_Mode
                        DISABLE,                    //ADC_ScanConvMode
                        DISABLE,                    //ADC_ContinuousConvMode
                        ADC_ExternalTrigConv_None,  //ADC_ExternalTrigConv
                        ADC_DataAlign_Right,        //ADC_DataAlign
                        1};                         //ADC_NbrOfChannel
private:
    /// Interrupt handler for EOC event
    virtual void end_of_conversion();

    //TODO: ADC1 specific below.
    /// Physical IRQ itself
    friend void ADC1_IRQHandler();
    /// IRQ configuration
    irq<ADC1_IRQn> _irq;

    /*
    PinIn _pa0{a0,GPIO_Mode_AIN};// ADC1_IN0
    PinIn _pa1{a1,GPIO_Mode_AIN};// ADC1_IN1
    PinIn _pa2{a2,GPIO_Mode_AIN};// ADC1_IN2
    PinIn _pa3{a3,GPIO_Mode_AIN};// ADC1_IN3
    PinIn _pa4{a4,GPIO_Mode_AIN};// ADC1_IN4
    PinIn _pa5{a5,GPIO_Mode_AIN};// ADC1_IN5
    PinIn _pa6{a6,GPIO_Mode_AIN};// ADC1_IN6
    PinIn _pa7{a7,GPIO_Mode_AIN};// ADC1_IN7
    PinIn _pb0{b0,GPIO_Mode_AIN};// ADC1_IN8
    PinIn _pb1{b1,GPIO_Mode_AIN};// ADC1_IN9
    PinIn _pc0{c0,GPIO_Mode_AIN};// ADC1_IN10
    PinIn _pc1{c1,GPIO_Mode_AIN};// ADC1_IN11
    PinIn _pc2{c2,GPIO_Mode_AIN};// ADC1_IN12
    PinIn _pc3{c3,GPIO_Mode_AIN};// ADC1_IN13
    PinIn _pc4{c4,GPIO_Mode_AIN};// ADC1_IN14
    PinIn _pc5{c5,GPIO_Mode_AIN};// ADC1_IN15
    */
};

using Analog=AnalogX<APB2>;


#endif // ADC_H
