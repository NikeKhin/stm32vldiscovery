#include "tim.h"



Timer6::Timer6():/*bus(Bus1()),*/base(TIM6)//,pin(APinID::pa0)
{
    //bus->enable(PeripheralID::tim6);
    //TODO: find correct HAL function
    TIM6->PSC = 0;//24000-1;//Divider (24MHz/(PSC+1))
    TIM6->ARR = 500;//1000;//Interrupt on every ARR tick
    TIM6->DIER |= TIM_DIER_UIE; //Enable interrupt generation
    TIM6->CR1 |= TIM_CR1_CEN; //Start timer
    NVIC_EnableIRQ(TIM6_DAC_IRQn); //Enable TIM6_DAC_IRQn at interrupt controller

    /*
TIM_TimeBaseInitTypeDef timer;
TIM_TimeBaseStructInit(&timer);
   timer.TIM_Prescaler =
    timer.TIM_Period = ;
     TIM_TimeBaseInit(TIM3, &timer);

TIM_IT_Update
TIM_IT_CC1
TIM_IT_CC2
TIM_IT_CC3
TIM_IT_CC4
TIM_IT_COM
TIM_IT_Trigger
TIM_IT_Break
     TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
      TIM_Cmd(TIM3, ENABLE);
      NVIC_EnableIRQ(TIM3_IRQn);
      */
};
Timer6::~Timer6()
{
   TIM_DeInit(base);
}

void TIM4_IRQHandler()
{
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
}
