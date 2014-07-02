#ifndef COMMON_H
#define COMMON_H

/** For STM32VLDISCOVERY included in mode of STM32F10X_MD_VL: STM32 Medium density Value Line devices */
#include <stm32f10x.h>
#include "STM32vldiscovery.h"


enum class LedID : uint8_t
{
    blue,green
};
/**
    Not a strongly typed enum to simply export of enumerator names into enclosing scope
*/
enum APin : uint16_t
{
    a0=GPIO_Pin_0,a1=0x0002,a2=0x0004,a3=0x0008,a4=0x0010,a5=0x0020,a6=0x0040,a7=0x0080,a8=0x0100,a9=0x0200,a10=0x0400,a11=0x0800,a12=0x1000,a13=0x2000,a14=0x4000,a15=0x8000
};
enum BPin : uint16_t
{
    b0=0x0001,b1=0x0002,b2=0x0004,b3=0x0008,b4=0x0010,b5=0x0020,b6=0x0040,b7=0x0080,b8=0x0100,b9=0x0200,b10=0x0400,b11=0x0800,b12=0x1000,b13=0x2000,b14=0x4000,b15=0x8000
};
enum CPin : uint16_t
{
    c0=0x0001,c1=0x0002,c2=0x0004,c3=0x0008,c4=0x0010,c5=0x0020,c6=0x0040,c7=0x0080,c8=0x0100,c9=0x0200,c10=0x0400,c11=0x0800,c12=0x1000,c13=0x2000,c14=0x4000,c15=0x8000
};
enum DPin : uint16_t
{
    d0=0x0001,d1=0x0002,d2=0x0004,d3=0x0008,d4=0x0010,d5=0x0020,d6=0x0040,d7=0x0080,d8=0x0100,d9=0x0200,d10=0x0400,d11=0x0800,d12=0x1000,d13=0x2000,d14=0x4000,d15=0x8000
};
enum EPin : uint16_t
{
    e0=0x0001,e1=0x0002,e2=0x0004,e3=0x0008,e4=0x0010,e5=0x0020,e6=0x0040,e7=0x0080,e8=0x0100,e9=0x0200,e10=0x0400,e11=0x0800,e12=0x1000,e13=0x2000,e14=0x4000,e15=0x8000
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
