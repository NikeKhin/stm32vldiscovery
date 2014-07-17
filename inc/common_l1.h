#ifndef COMMON_L1_H
#define COMMON_L1_H

/**
    STM32L1XX_MD: STM32L Ultra Low Power Medium-density devices
    STM32L1XX_MDP: STM32L Ultra Low Power Medium-density Plus devices
    STM32L1XX_HD: STM32L Ultra Low Power High-density devices
*/
#include <stm32l1xx.h>

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
    tim2=RCC_APB1Periph_TIM2,
    tim3=RCC_APB1Periph_TIM3,
    tim4=RCC_APB1Periph_TIM4,
    tim5=RCC_APB1Periph_TIM5,
    tim6=RCC_APB1Periph_TIM6,
    tim7=RCC_APB1Periph_TIM7,
    lcd=RCC_APB1Periph_LCD,
    wwdg=RCC_APB1Periph_WWDG,
    spi2=RCC_APB1Periph_SPI2,
    spi3=RCC_APB1Periph_SPI3,
    usart2=RCC_APB1Periph_USART2,
    usart3=RCC_APB1Periph_USART3,
    uart4=RCC_APB1Periph_UART4,
    uart5=RCC_APB1Periph_UART5,
    i2c1=RCC_APB1Periph_I2C1,
    i2c2=RCC_APB1Periph_I2C2,
    usb=RCC_APB1Periph_USB,
    pwr=RCC_APB1Periph_PWR,
    dac=RCC_APB1Periph_DAC,
    comp=RCC_APB1Periph_COMP,
    apb1_none=0
};
/**
  @class APB2
  @brief Enumeration of all APB2 devices, initialized with original values from SPL.

  Intended for use as a template parameter for various device classes
 */
enum APB2: uint32_t
{
    syscfg=RCC_APB2Periph_SYSCFG,
    tim9=RCC_APB2Periph_TIM9,
    tim10=RCC_APB2Periph_TIM10,
    tim11=RCC_APB2Periph_TIM11,
    adc1=RCC_APB2Periph_ADC1,
    sdio=RCC_APB2Periph_SDIO,
    spi1=RCC_APB2Periph_SPI1,
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
    gpioa=RCC_AHBPeriph_GPIOA,
    gpiob=RCC_AHBPeriph_GPIOB,
    gpioc=RCC_AHBPeriph_GPIOC,
    gpiod=RCC_AHBPeriph_GPIOD,
    gpioe=RCC_AHBPeriph_GPIOE,
    gpiof=RCC_AHBPeriph_GPIOF,
    gpiog=RCC_AHBPeriph_GPIOG,
    gpioh=RCC_AHBPeriph_GPIOH,
    crc=RCC_AHBPeriph_CRC,
    flitf=RCC_AHBPeriph_FLITF,
    sram=RCC_AHBPeriph_SRAM,
    dma1=RCC_AHBPeriph_DMA1,
    dma2=RCC_AHBPeriph_DMA2,
    aes=RCC_AHBPeriph_AES,
    fsmc=RCC_AHBPeriph_FSMC,
    ahb_none=0
};

#define MODE_OUT GPIO_Mode_OUT
#define MODE_IN GPIO_Mode_IN
#define MODE_ANALOG GPIO_Mode_AN

class adc_init_t{
public:
    ADC_InitTypeDef init;
    adc_init_t(uint32_t trigger, uint8_t channel_count);
};


#endif // COMMON_L1_H
