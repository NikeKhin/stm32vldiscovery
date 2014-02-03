#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

template<class T>
class Pin
{
public:
    Pin(T id);
    //Pin(APinID id);
    //Pin(BPinID id);
    //Pin(CPinID id);
    //Pin(DPinID id);
    //Pin(EPinID id);
    void setupSlowOutAnalog();
    void setupSlowInAnalog();
private:
    APB &bus;
    uint16_t pin;
    GPIO_TypeDef* base = nullptr;
};

#endif // PIN_H