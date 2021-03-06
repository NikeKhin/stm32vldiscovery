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
*/
class Timer: public Device
{
public:
    Timer(const APB1 id, Time period);
    Timer(const APB2 id, Time period);
    ~Timer();
    uint32_t trigger() const;
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
