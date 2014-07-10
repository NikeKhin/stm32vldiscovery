#ifndef TIM_H
#define TIM_H

#include "common.h"
#include "bus.h"

/// TIM IRQ handler to get C-linkage
extern "C"
void TIM3_IRQHandler();
/*
  TIM1_BRK_TIM15_IRQHandler
  TIM1_UP_TIM16_IRQHandler
  TIM1_TRG_COM_TIM17_IRQHandler
  TIM1_CC_IRQHandler
  TIM2_IRQHandler
  TIM3_IRQHandler
  TIM4_IRQHandler
  TIM6_DAC_IRQHandler
  TIM7_IRQHandler
 */


/**
    @class Timer
    @brief Implementation of Timer device

    Possible template parameters AHB
    @param T the bus enum type, containing its peripheral device identifiers (e.g. AHB1 or AHB2)
        @arg AHB1
        @arg AHB2
*/
class Timer: public Device
{
public:
    Timer(APB1 id);
    Timer(APB2 id);
    ~Timer();
    //virtual void start() = 0;
    //virtual void stop() = 0;
private:
    /// Timer handle structure. Declared in standard peripheral library
    TIM_TypeDef* _base = nullptr;
    //TODO: TIM3 specific below.
    /// Physical IRQ itself
    friend void TIM3_IRQHandler();
    /// IRQ configuration
    irq _irq;
};


#endif // TIM_H
