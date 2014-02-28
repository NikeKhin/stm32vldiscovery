#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

class IOPort
{
    enum : uint8_t {p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15};
    uint16_t read();
    void write(uint16_t value);
};

class PinBase
{
protected:
    uint16_t pin;
    PinBase(uint8_t id){
        this->pin = 0x0001 << id;
    };
};

template<class T>
class Pin: public PinBase
{
public:
    Pin(T id);
    void setupSlowOutAnalog()
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(base, &GPIO_InitStructure);
    };
    void setupSlowInAnalog()
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(base, &GPIO_InitStructure);
    };
private:
    const APB *bus = nullptr;
    GPIO_TypeDef* base = nullptr;
};

#endif // PIN_H
