#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

/**
    @class Device
    @brief GPIO port (16-bit)

    Possible template parameters APB1 or APB2 and their corresponding values
    @param T - the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
    @param pid - peripheral GPIO device identifier (e.g. APB2::gpioc)
*/
template<typename T, T pid>
class Port: public Device<T>
{
    // TODO: some static staff (common for all class instances) may come here
    // i.e. the port state variables
protected:
    /// GPIO handle structure. Declared in standard peripheral library
    GPIO_TypeDef *_base;
public:
    /// Default specialized constructor
    Port();
    /// Read 16 bits of the port simultaneously
    uint16_t read(){
        return GPIO_ReadInputData(_base);
    }
    /// Write 16 bits of the port simultaneously
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
    @class Pin
    @brief Specific pin of a 16-bit GPIO port

    Possible template parameters are PortA...PortE (see type aliasing above)
    @param T - the type alias for the specific GPIO port (e.g. PortC)
*/
template<typename T>
class Pin: public T
{
protected:
    /// The set bit on the bit position of the pin number
    uint16_t _pin;
public:
    /// Constructs the pin
    /// @param id the pin number of the 16-pin port
    Pin(uint8_t id){
        //static_assert(id>15,"pin number of the 16-pin port should be in range 0:15");
        this->_pin = 0x0001 << id;
    };
    /// Set/reset current pin value
    /// @param value the boolean value of the set pin state
    void set(bool value){
        GPIO_WriteBit(T::_base, _pin, value?Bit_SET:Bit_RESET);
    }
    /// Get current pin state
    /// @returns bool the pin state
    bool get(){
        return static_cast<bool>(GPIO_ReadInputDataBit(T::_base, _pin));
        //TODO: uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    }

    /// Cast to bool with current pin state
    /// @returns bool the pin state
    operator bool(){
        return get();
    }
    Pin<T>& operator=(bool value){
        set(value);
        return *this;
    }
};


/**
    @class DigitalOut
    @brief Specific pin of a 16-bit GPIO port configured to be digital output push-pull mode

    Possible template parameters are PortA...PortE (see type aliasing above)
    @param T - the type alias for the specific GPIO port (e.g. PortC)
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
using DigitalOutA=DigitalOut<PortA>;
using DigitalOutB=DigitalOut<PortB>;
using DigitalOutC=DigitalOut<PortC>;
using DigitalOutD=DigitalOut<PortD>;
using DigitalOutE=DigitalOut<PortE>;



/**
    @class DigitalIn
    @brief Specific pin of a 16-bit GPIO port configured to be digital input mode

    Possible template parameters are PortA...PortE (see type aliasing above)
    @param T - the type alias for the specific GPIO port (e.g. PortC)
*/
template<typename T>
class DigitalIn: public Pin<T>
{
public:
    DigitalIn(uint8_t id):Pin<T>(id){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = Pin<T>::_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(T::_base, &GPIO_InitStructure);
    }
};
using DigitalInA=DigitalIn<PortA>;
using DigitalInB=DigitalIn<PortB>;
using DigitalInC=DigitalIn<PortC>;
using DigitalInD=DigitalIn<PortD>;
using DigitalInE=DigitalIn<PortE>;









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
