#ifndef COMMON_H
#define COMMON_H

#include <stm32f10x.h>
#include "STM32vldiscovery.h"


enum class LedID : uint8_t
{
    blue,green
};

enum class APinID : uint16_t
{
    p0=0x0001,p1=0x0002,p2=0x0004,p3=0x0008,p4=0x0010,p5=0x0020,p6=0x0040,p7=0x0080,p8=0x0100,p9=0x0200,p10=0x0400,p11=0x0800,p12=0x1000,p13=0x2000,p14=0x4000,p15=0x8000
};
enum class BPinID : uint16_t
{
    p0=0x0001,p1=0x0002,p2=0x0004,p3=0x0008,p4=0x0010,p5=0x0020,p6=0x0040,p7=0x0080,p8=0x0100,p9=0x0200,p10=0x0400,p11=0x0800,p12=0x1000,p13=0x2000,p14=0x4000,p15=0x8000
};
enum class CPinID : uint16_t
{
    p0=0x0001,p1=0x0002,p2=0x0004,p3=0x0008,p4=0x0010,p5=0x0020,p6=0x0040,p7=0x0080,p8=0x0100,p9=0x0200,p10=0x0400,p11=0x0800,p12=0x1000,p13=0x2000,p14=0x4000,p15=0x8000
};
enum class DPinID : uint16_t
{
    p0=0x0001,p1=0x0002,p2=0x0004,p3=0x0008,p4=0x0010,p5=0x0020,p6=0x0040,p7=0x0080,p8=0x0100,p9=0x0200,p10=0x0400,p11=0x0800,p12=0x1000,p13=0x2000,p14=0x4000,p15=0x8000
};
enum class EPinID : uint16_t
{
    p0=0x0001,p1=0x0002,p2=0x0004,p3=0x0008,p4=0x0010,p5=0x0020,p6=0x0040,p7=0x0080,p8=0x0100,p9=0x0200,p10=0x0400,p11=0x0800,p12=0x1000,p13=0x2000,p14=0x4000,p15=0x8000
};


/**
  @class APB1
  @brief Enumeration of all APB1 devices, initialized with original values from SPL.

  Intended for use as a template parameter for various device classes
 */
enum class APB1 : uint32_t
{
    bkp=RCC_APB1Periph_BKP,
    cec=RCC_APB1Periph_CEC,
    dac=RCC_APB1Periph_DAC,
    i2c1=RCC_APB1Periph_I2C1,
    i2c2=RCC_APB1Periph_I2C2,
    pwr=RCC_APB1Periph_PWR,
    spi2=RCC_APB1Periph_SPI2,
    tim2=RCC_APB1Periph_TIM2,
    tim3=RCC_APB1Periph_TIM3,
    tim4=RCC_APB1Periph_TIM4,
    tim5=RCC_APB1Periph_TIM5,
    tim6=RCC_APB1Periph_TIM6,
    tim7=RCC_APB1Periph_TIM7,
    usart2=RCC_APB1Periph_USART2,
    usart3=RCC_APB1Periph_USART3,
    wwdg=RCC_APB1Periph_WWDG,
    the_bus
};
/**
  @class APB2
  @brief Enumeration of all APB2 devices, initialized with original values from SPL.

  Intended for use as a template parameter for various device classes
 */
enum class APB2: uint32_t
{
    adc1=RCC_APB2Periph_ADC1,
    afio=RCC_APB2Periph_AFIO,
    gpioa=RCC_APB2Periph_GPIOA,
    gpiob=RCC_APB2Periph_GPIOB,
    gpioc=RCC_APB2Periph_GPIOC,
    gpiod=RCC_APB2Periph_GPIOD,
    gpioe=RCC_APB2Periph_GPIOE,
    spi1=RCC_APB2Periph_SPI1,
    tim1=RCC_APB2Periph_TIM1,
    tim15=RCC_APB2Periph_TIM15,
    tim16=RCC_APB2Periph_TIM16,
    tim17=RCC_APB2Periph_TIM17,
    usart1=RCC_APB2Periph_USART1,
    the_bus
};
/**
  @class AHB
  @brief Enumeration of all APB1 devices, initialized with original values from SPL.

  Intended for use as a template parameter for various device classes
 */
enum class AHB: uint32_t
{
    crc=RCC_AHBPeriph_CRC,
    dma1=RCC_AHBPeriph_DMA1,
    the_bus
};


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
    uint64_t ticks(){
        return HSE_VALUE*_time/1000000UL;
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

#endif // COMMON_H
