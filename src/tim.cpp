#include "tim.h"

template<>
Timer<APB1>::Timer(APB1 id):
    Device{id},
    _base{ TIM3 } // TODO: hardcoded
{
    TIM_TimeBaseInitTypeDef timer;
    TIM_TimeBaseStructInit(&timer);
    timer.TIM_Prescaler = 24000-1;
    timer.TIM_Period = 1000;
    TIM_TimeBaseInit(_base, &timer);
    /*
    TIM_IT_Update
    TIM_IT_CC1
    TIM_IT_CC2
    TIM_IT_CC3
    TIM_IT_CC4
    TIM_IT_COM
    TIM_IT_Trigger
    TIM_IT_Break
    */
    _irq(TIM3_IRQn);
    TIM_ITConfig(_base, TIM_IT_Update, ENABLE);
    TIM_Cmd(_base, ENABLE);
    NVIC_EnableIRQ(TIM3_IRQn);
}



    /*
TIM_TimeBaseInitTypeDef timer;
TIM_TimeBaseStructInit(&timer);
   timer.TIM_Prescaler =
    timer.TIM_Period = ;
     TIM_TimeBaseInit(TIM3, &timer);

     see also
     TIM_SetCompare2(TIM2 , pw);
     TIM_OC2Init

      */

template<>
Timer<APB1>::~Timer()
{
   TIM_DeInit(_base);
}


/**
    @brief Extern C IRQ handler for TIM3
*/
void TIM3_IRQHandler()
{
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
}
