#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

template<PeripheralID port, typename T_busname>
class Port: public Device<T_busname>
{
    //some static staff (common for all class instances) may come here
    // i.e. the port state variables
protected:
    GPIO_TypeDef *base;
public:
    Port(PeripheralID pid);

    uint16_t read();
    void write(uint16_t value);
};

//TODO: check port-bus correspondence. It is definitely wrong
using PortA = Port<PeripheralID::gpioa,Bus2>;
using PortB = Port<PeripheralID::gpiob,Bus2>;
using PortC = Port<PeripheralID::gpioc,Bus2>;
using PortD = Port<PeripheralID::gpiod,Bus2>;
using PortE = Port<PeripheralID::gpioe,Bus2>;
//using PortF = Port<GPIOF,Bus2>;
//using PortG = Port<GPIOG,Bus2>;



template<class T_portname>
class Pin: public T_portname
{
protected:
    uint16_t pin;
public:
    Pin(uint8_t id){
        this->pin = 0x0001 << id;
    };
    void setupSlowOutAnalog()
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        //GPIO_Init(base, &GPIO_InitStructure);
    };
    void setupSlowInAnalog()
    {
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        //GPIO_Init(base, &GPIO_InitStructure);
    };
};

using PinA = Pin<PortA>;
using PinB = Pin<PortB>;
using PinC = Pin<PortC>;
using PinD = Pin<PortD>;
using PinE = Pin<PortE>;
//using PinF = Pin<PortF>;
//using PinG = Pin<PortG>;

#endif // PIN_H
