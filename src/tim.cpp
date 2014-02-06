#include "tim.h"


//TODO: move
extern APB1 bus1;
extern APB2 bus2;

Timer6::Timer6():bus(Bus<APB1>()),base(TIM6)//,pin(APinID::pa0)
{
    bus->enable(PeripheralID::tim6);
    //TODO: find correct HAL function
    TIM6->PSC = 0;//24000-1;//Divider (24MHz/(PSC+1))
    TIM6->ARR = 500;//1000;//Interrupt on every ARR tick
    TIM6->DIER |= TIM_DIER_UIE; //Enable interrupt generation
    TIM6->CR1 |= TIM_CR1_CEN; //Start timer
    NVIC_EnableIRQ(TIM6_DAC_IRQn); //Enable TIM6_DAC_IRQn at interrupt controller
};
Timer6::~Timer6()
{
   TIM_DeInit(base);
}
