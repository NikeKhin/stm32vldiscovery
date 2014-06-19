#ifndef TIM_H
#define TIM_H

#include "common.h"
#include "bus.h"

//---------------------------------
class Timer
{
public:
    //virtual void start() = 0;
    //virtual void stop() = 0;
};
class Timer6:public Timer
{
public:
    Timer6();
    ~Timer6();
private:
    TIM_TypeDef* base = nullptr;
    //const BusBase *bus = nullptr;
    //Pin pin;
};

#endif // TIM_H
