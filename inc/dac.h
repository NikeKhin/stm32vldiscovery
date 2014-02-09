#ifndef DAC_H
#define DAC_H

#include "common.h"
#include "bus.h"
#include "pin.h"
#include "tim.h"

//---------------------------------
class Dac
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    static void tick();
};

class Dac1:public Dac
{
public:
    Dac1();
    ~Dac1();
    void start();
    void stop();
private:
    DAC_TypeDef* base = nullptr;//TODO: DAC channel is important
    const APB *bus = nullptr;
    Pin<APinID> pin = {APinID::pa4};
    Timer6 tim;
};

#endif // DAC_H
