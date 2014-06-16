#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

template<typename T, T pid>
class Port: public Device<T>
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

using PortA = Port<APB2, APB2::gpioa>;
using PortB = Port<APB2, APB2::gpiob>;
using PortC = Port<APB2, APB2::gpioc>;
using PortD = Port<APB2, APB2::gpiod>;
using PortE = Port<APB2, APB2::gpioe>;

template<typename T>
class Pin: public T
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
