#ifndef COMMON_H
#define COMMON_H

/**
    For STM32VLDISCOVERY included in mode of STM32F10X_MD_VL: STM32 Medium density Value Line devices
*/
#ifdef STM32F10X_MD_VL
#include "common_f1.h"
#endif

/**
    STM32L1XX_MD: STM32L Ultra Low Power Medium-density devices
    STM32L1XX_MDP: STM32L Ultra Low Power Medium-density Plus devices
    STM32L1XX_HD: STM32L Ultra Low Power High-density devices
*/
#ifdef STM32L1XX_MD
#include "common_l1.h"
#endif


void gpio_defaults(GPIO_InitTypeDef *GPIO_InitStructure, GPIOMode_TypeDef mode);


class Time{
    /// The time in microseconds
    uint64_t _time;
public:
    /// Literal should have constexpr constructor
    constexpr Time(uint64_t t):_time{t}{
    }
    /// Convert to long integer type
    operator uint64_t(){
        return _time;
    }
    /// Convert the time to ticks using External High Speed oscillator (HSE) speed value
    uint64_t ticks(uint16_t prescaler=1){
        return (SystemCoreClock/prescaler)*_time/1000000UL;
    }
};

constexpr Time  operator"" _s(uint64_t t){
    return t*1000000UL;
}
constexpr Time operator"" _ms(uint64_t t){
    return t*1000UL;
}
constexpr Time operator"" _us(uint64_t t){
    return t*1UL;
}


void wait(Time us);


class irq {
public:
    /// Not specialized constructor
    irq(){
      // Everything is preemptive
      NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    }
    /// Specialized for each IRQ type
    void operator()(IRQn n);
};


#endif // COMMON_H
