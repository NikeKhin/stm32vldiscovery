#ifndef ADC_H
#define ADC_H

#include "common.h"
#include "bus.h"
#include "pin.h"
#include "tim.h"

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
class Analog: public Device
{
public:
    /// Overloaded constructor
    Analog(const APB1 id);
    Analog(const APB2 id);
    /// Starts conversion
    virtual void start(const Timer *_tim=nullptr);
    /// Stops conversion
    virtual void stop();
    /// Read 16 bits of the ADC data port
    virtual uint16_t read();
    /// Destruct and deinit ADC resources
    virtual ~Analog();
    /// All registered ADC's
    static Analog* adc[];
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
    irq _irq;
    /// Internal timer
    Timer *_tim;
    /// ADC channel sequence nimber (1 to 16) for sequential conversion
    int channel_priority{1};

    /// Nested channel type
    template <typename U, U id, uint8_t channel>
    class Channel {
    public:
        Channel(Analog &adc):_p{id,GPIO_Mode_AIN},_adc(adc){
            ADC_RegularChannelConfig(_adc._base, channel, _adc.channel_priority++, ADC_SampleTime_1Cycles5);
        }
        uint16_t read(){ return 0;}
        ~Channel(){_adc.channel_priority++;}
    private:
        PinIn _p;
        Analog &_adc;
    };
    /// Specialization for special 16 and 17 channels not attached to pins
    template <uint8_t channel>
    class Channel<int,0,channel> {
    public:
        Channel(Analog &adc){
            // TODO: Excessive for the 17th channel but let it be
            ADC_TempSensorVrefintCmd(ENABLE);
            ADC_RegularChannelConfig(adc._base, channel, adc.channel_priority++, ADC_SampleTime_1Cycles5);
        }
        ~Channel(){_adc.channel_priority++;}
    private:
        Analog &_adc;
    };

public:
    /// Priority is assigned in the order of construction
    using in0 = Channel<APin, a0, ADC_Channel_0>;// ADC1_IN0
    using in1 = Channel<APin, a1, ADC_Channel_1>;// ADC1_IN1
    using in2 = Channel<APin, a2, ADC_Channel_2>;// ADC1_IN2
    using in3 = Channel<APin, a3, ADC_Channel_3>;// ADC1_IN3
    using in4 = Channel<APin, a4, ADC_Channel_4>;// ADC1_IN4
    using in5 = Channel<APin, a5, ADC_Channel_5>;// ADC1_IN5
    using in6 = Channel<APin, a6, ADC_Channel_6>;// ADC1_IN6
    using in7 = Channel<APin, a7, ADC_Channel_7>;// ADC1_IN7
    using in8 = Channel<BPin, b0, ADC_Channel_8>;// ADC1_IN8
    using in9 = Channel<BPin, b1, ADC_Channel_9>;// ADC1_IN9
    using in10= Channel<CPin, c0, ADC_Channel_10>;// ADC1_IN10
    using in11= Channel<CPin, c1, ADC_Channel_11>;// ADC1_IN11
    using in12= Channel<CPin, c2, ADC_Channel_12>;// ADC1_IN12
    using in13= Channel<CPin, c3, ADC_Channel_13>;// ADC1_IN13
    using in14= Channel<CPin, c4, ADC_Channel_14>;// ADC1_IN14
    using in15= Channel<CPin, c5, ADC_Channel_15>;// ADC1_IN15
    using in16= Channel<int,   0, ADC_Channel_16>;// ADC1_IN16
    using in17= Channel<int,   0, ADC_Channel_17>;// ADC1_IN17
};


#endif // ADC_H
