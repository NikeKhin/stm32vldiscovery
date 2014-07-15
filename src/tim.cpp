#include "tim.h"


Timer::Timer(const APB1 id, Time period):
    Device {id},
    _base { tim_base(id,apb1_timers) }
{
    TIM_TimeBaseInitTypeDef timer;
    TIM_TimeBaseStructInit(&timer);
    timer.TIM_Prescaler = 24000-1;
    timer.TIM_Period = period.ticks();
    TIM_TimeBaseInit(_base, &timer);

    /*
     TIM_TRGOSource: specifies the Trigger Output source.
     This paramter can be one of the following values:
       - For all TIMx
          TIM_TRGOSource_Reset:  The UG bit in the TIM_EGR register is used as the trigger output (TRGO).
          TIM_TRGOSource_Enable: The Counter Enable CEN is used as the trigger output (TRGO).
          TIM_TRGOSource_Update: The update event is selected as the trigger output (TRGO).

       - For all TIMx except TIM6 and TIM7
          TIM_TRGOSource_OC1: The trigger output sends a positive pulse when the CC1IF flag
                              is to be set, as soon as a capture or compare match occurs (TRGO).
          TIM_TRGOSource_OC1Ref: OC1REF signal is used as the trigger output (TRGO).
          TIM_TRGOSource_OC2Ref: OC2REF signal is used as the trigger output (TRGO).
          TIM_TRGOSource_OC3Ref: OC3REF signal is used as the trigger output (TRGO).
          TIM_TRGOSource_OC4Ref: OC4REF signal is used as the trigger output (TRGO).
    */
    TIM_SelectOutputTrigger (_base, TIM_TRGOSource_Update);
    TIM_ARRPreloadConfig(_base, ENABLE);
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
    //_irq(TIM3_IRQn);
    //TIM_ITConfig(_base, TIM_IT_Update, ENABLE);
    TIM_Cmd(_base, ENABLE);
    //NVIC_EnableIRQ(TIM3_IRQn);
}
Timer::Timer(APB2 id, Time period):
    Device {id},
    _base { tim_base(id,apb2_timers) }
{

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

Timer::~Timer()
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
