#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

template<PeripheralID pid>
class Port: public Device
{
    //some static staff (common for all class instances) may come here
    // i.e. the port state variables
protected:
    GPIO_TypeDef *base;
public:
    Port();

    uint16_t read(){
        //uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
    }
    void write(uint16_t value){
        //void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
    }
};

using PortA = Port<PeripheralID::gpioa>;
using PortB = Port<PeripheralID::gpiob>;
using PortC = Port<PeripheralID::gpioc>;
using PortD = Port<PeripheralID::gpiod>;
using PortE = Port<PeripheralID::gpioe>;


template<typename T_portname>
class Pin: public T_portname
{
protected:
    uint16_t _pin;
public:
    Pin(uint8_t id){
        this->_pin = 0x0001 << id;
    };
    void set(bool value){
        //void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
    }
    bool get(){
        //uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
        //uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    }
};
/*
using PinA = Pin<PortA>;
using PinB = Pin<PortB>;
using PinC = Pin<PortC>;
using PinD = Pin<PortD>;
using PinE = Pin<PortE>;
*/

template<typename T_portname>
class InFloatingPin: public Pin<T_portname>
{
public:
    InFloatingPin(uint8_t id):Pin<T_portname>(id){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = Pin<T_portname>::_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(T_portname::base, &GPIO_InitStructure);
    }
};
template<typename T_portname>
class OutAnalogPin: public Pin<T_portname>
{
public:
    OutAnalogPin(uint8_t id):Pin<T_portname>(id){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = Pin<T_portname>::_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(T_portname::base, &GPIO_InitStructure);
    }

};


#endif // PIN_H
