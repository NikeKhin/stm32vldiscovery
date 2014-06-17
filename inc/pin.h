#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

/**
    @brief GPIO port (16-bit)
    Possible template parameters APB1 or APB2 and their corresponding values
    @class Device
*/
template<typename T, T pid>
class Port: public Device<T>
{
    //some static staff (common for all class instances) may come here
    // i.e. the port state variables
protected:
    /// Declared in standard peripheral library
    GPIO_TypeDef *_base;
public:
    /**
      @brief Default specialized constructor
    */
    Port();

    /**
      @brief Read 16 bits of the port simultaneously
    */
    uint16_t read(){
        return GPIO_ReadInputData(_base);
    }
    /**
      @brief Write 16 bits of the port simultaneously
    */
    void write(uint16_t value){
        GPIO_Write(_base, value);
    }
};

/**
    Specific port names
*/
using PortA = Port<APB2, APB2::gpioa>;
using PortB = Port<APB2, APB2::gpiob>;
using PortC = Port<APB2, APB2::gpioc>;
using PortD = Port<APB2, APB2::gpiod>;
using PortE = Port<APB2, APB2::gpioe>;


/**
    @brief Specific pin of a 16-bit GPIO port
    Possible template parameters are PortA...PortE (see type aliasing above)
    @class Pin
*/
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
        GPIO_WriteBit(T::_base, _pin, value?Bit_SET:Bit_RESET);
    }
    bool get(){
        //uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
        //uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    }
};


/**
    @brief Specific pin of a 16-bit GPIO port configured to be digital output push-pull mode
    Possible template parameters are PortA...PortE (see type aliasing above)
    @class Device
*/
template<typename T>
class DigitalOut: public Pin<T>
{
public:
    DigitalOut(uint8_t id):Pin<T>(id){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = Pin<T>::_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(T::_base, &GPIO_InitStructure);
    }
};


/**
    @brief Specific pin of a 16-bit GPIO port configured to be floating input
    Possible template parameters are PortA...PortE (see type aliasing above)
    @class Device
*/
template<typename T>
class InFloatingPin: public Pin<T>
{
public:
    InFloatingPin(uint8_t id):Pin<T>(id){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = Pin<T>::_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(T::_base, &GPIO_InitStructure);
    }
};


template<typename T>
class OutAnalogPin: public Pin<T>
{
public:
    OutAnalogPin(uint8_t id):Pin<T>(id){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = Pin<T>::_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(T::_base, &GPIO_InitStructure);
    }

};


#endif // PIN_H
