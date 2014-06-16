#ifndef COMMON_H
#define COMMON_H

#include <stm32f10x.h>
#include "STM32vldiscovery.h"


enum class LedID : uint8_t
{
    blue,green
};
enum class APinID : uint8_t
{
    pa0,pa1,pa2,pa3,pa4,pa5,pa6,pa7,pa8,pa9,pa10,pa11,pa12,pa13,pa14,pa15
};
enum class BPinID : uint8_t
{
    pb0,pb1,pb2,pb3,pb4,pb5,pb6,pb7,pb8,pb9,pb10,pb11,pb12,pb13,pb14,pb15
};
enum class CPinID : uint8_t
{
    pc0,pc1,pc2,pc3,pc4,pc5,pc6,pc7,pc8,pc9,pc10,pc11,pc12,pc13,pc14,pc15
};
enum class DPinID : uint8_t
{
    pd0,pd1,pd2,pd3,pd4,pd5,pd6,pd7,pd8,pd9,pd10,pd11,pd12,pd13,pd14,pd15
};
enum class EPinID : uint8_t
{
    pe0,pe1,pe2,pe3,pe4,pe5,pe6,pe7,pe8,pe9,pe10,pe11,pe12,pe13,pe14,pe15
};


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
enum class AHB: uint32_t
{
    crc=RCC_AHBPeriph_CRC,
    dma1=RCC_AHBPeriph_DMA1,
    the_bus
};


#endif // COMMON_H
