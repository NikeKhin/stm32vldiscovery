#ifndef COMMON_F1_H
#define COMMON_F1_H

/** For STM32VLDISCOVERY included in mode of STM32F10X_MD_VL: STM32 Medium density Value Line devices */
#include <stm32f10x.h>

/**
    Not a strongly typed enum to simply export of enumerator names into enclosing scope
*/
enum APin : uint16_t
{
    a0=GPIO_Pin_0,
    a1=GPIO_Pin_1,
    a2=GPIO_Pin_2,
    a3=GPIO_Pin_3,
    a4=GPIO_Pin_4,
    a5=GPIO_Pin_5,
    a6=GPIO_Pin_6,
    a7=GPIO_Pin_7,
    a8=GPIO_Pin_8,
    a9=GPIO_Pin_9,
    a10=GPIO_Pin_10,
    a11=GPIO_Pin_11,
    a12=GPIO_Pin_12,
    a13=GPIO_Pin_13,
    a14=GPIO_Pin_14,
    a15=GPIO_Pin_15,
    a=GPIO_Pin_All
};
enum BPin : uint16_t
{
    b0=GPIO_Pin_0,
    b1=GPIO_Pin_1,
    b2=GPIO_Pin_2,
    b3=GPIO_Pin_3,
    b4=GPIO_Pin_4,
    b5=GPIO_Pin_5,
    b6=GPIO_Pin_6,
    b7=GPIO_Pin_7,
    b8=GPIO_Pin_8,
    b9=GPIO_Pin_9,
    b10=GPIO_Pin_10,
    b11=GPIO_Pin_11,
    b12=GPIO_Pin_12,
    b13=GPIO_Pin_13,
    b14=GPIO_Pin_14,
    b15=GPIO_Pin_15,
    b=GPIO_Pin_All
};
enum CPin : uint16_t
{
    c0=GPIO_Pin_0,
    c1=GPIO_Pin_1,
    c2=GPIO_Pin_2,
    c3=GPIO_Pin_3,
    c4=GPIO_Pin_4,
    c5=GPIO_Pin_5,
    c6=GPIO_Pin_6,
    c7=GPIO_Pin_7,
    c8=GPIO_Pin_8,
    c9=GPIO_Pin_9,
    c10=GPIO_Pin_10,
    c11=GPIO_Pin_11,
    c12=GPIO_Pin_12,
    c13=GPIO_Pin_13,
    c14=GPIO_Pin_14,
    c15=GPIO_Pin_15,
    c=GPIO_Pin_All
};
enum DPin : uint16_t
{
    d0=GPIO_Pin_0,
    d1=GPIO_Pin_1,
    d2=GPIO_Pin_2,
    d3=GPIO_Pin_3,
    d4=GPIO_Pin_4,
    d5=GPIO_Pin_5,
    d6=GPIO_Pin_6,
    d7=GPIO_Pin_7,
    d8=GPIO_Pin_8,
    d9=GPIO_Pin_9,
    d10=GPIO_Pin_10,
    d11=GPIO_Pin_11,
    d12=GPIO_Pin_12,
    d13=GPIO_Pin_13,
    d14=GPIO_Pin_14,
    d15=GPIO_Pin_15,
    d=GPIO_Pin_All
};
enum EPin : uint16_t
{
    e0=GPIO_Pin_0,
    e1=GPIO_Pin_1,
    e2=GPIO_Pin_2,
    e3=GPIO_Pin_3,
    e4=GPIO_Pin_4,
    e5=GPIO_Pin_5,
    e6=GPIO_Pin_6,
    e7=GPIO_Pin_7,
    e8=GPIO_Pin_8,
    e9=GPIO_Pin_9,
    e10=GPIO_Pin_10,
    e11=GPIO_Pin_11,
    e12=GPIO_Pin_12,
    e13=GPIO_Pin_13,
    e14=GPIO_Pin_14,
    e15=GPIO_Pin_15,
    e=GPIO_Pin_All
};

/**
  @class APB1
  @brief Enumeration of all APB1 devices, initialized with original values from SPL.

  Intended for use as a template parameter for various device classes
 */
enum APB1 : uint32_t
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
    apb1_none=0
};
/**
  @class APB2
  @brief Enumeration of all APB2 devices, initialized with original values from SPL.

  Intended for use as a template parameter for various device classes
 */
enum APB2: uint32_t
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
    apb2_none=0
};
/**
  @class AHB
  @brief Enumeration of all APB1 devices, initialized with original values from SPL.

  Intended for use as a template parameter for various device classes
 */
enum AHB: uint32_t
{
    crc=RCC_AHBPeriph_CRC,
    dma1=RCC_AHBPeriph_DMA1,
    ahb_none=0
};

/// Redefinitions
#define MODE_OUT        GPIO_Mode_Out_PP
#define MODE_IN         GPIO_Mode_IN_FLOATING
#define MODE_ANALOG     GPIO_Mode_AIN

class adc_init_t{
public:
    ADC_InitTypeDef init;
    adc_init_t(uint32_t trigger, uint8_t channel_count);
};

// Timers
template <typename T>
struct apb_timer_t
{
    T id;
    TIM_TypeDef* base;
};
constexpr apb_timer_t<APB1> apb1_timers[] =
{
    { tim2, TIM2 },
    { tim3, TIM3 },
    { tim4, TIM4 },
    { tim5, TIM5 },
    { tim6, TIM6 },
    { tim7, TIM7 }
};
constexpr apb_timer_t<APB2> apb2_timers[] =
{
    { tim1, TIM1 },
    { tim15, TIM15 },
    { tim16, TIM16 },
    { tim17, TIM17 }
};


template <typename T>
constexpr TIM_TypeDef* tim_base(T id, apb_timer_t<T> const *timers)
{
    return (id == timers->id) ? timers->base : tim_base(id, timers+1);
}



#endif // COMMON_F1_H
