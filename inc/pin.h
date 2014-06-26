#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

/**
    @class Port
    @brief GPIO port (16-bit)

    Possible template parameters APB1 or APB2 and their corresponding values
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
    @param pid peripheral GPIO device identifier (e.g. APB2::gpioc)
*/
template<typename T, T pid>
class Port: public Device<T>
{
public:
    /// Default specialized constructor
    Port();
    /// Read 16 bits of the port simultaneously
    /// @returns 16-bit port value
    uint16_t read(){
        return GPIO_ReadInputData(_base);
    }
    /// Write 16 bits of the port simultaneously
    /// @param 16-bit port value
    void write(uint16_t value){
        GPIO_Write(_base, value);
    }
protected:
    /// GPIO handle structure. Declared in standard peripheral library
    GPIO_TypeDef *_base = nullptr;
};

/**
    Specific port names
*/
using PortA = Port<APB2, APB2::gpioa>;
using PortB = Port<APB2, APB2::gpiob>;
using PortC = Port<APB2, APB2::gpioc>;
using PortD = Port<APB2, APB2::gpiod>;
using PortE = Port<APB2, APB2::gpioe>;



template<typename T>
class Portx: public Device<T>
{
protected:
    /// The set bit on the bit position of the pin number
    uint16_t _pin;
public:
    Portx(APinID pin);
    Portx(BPinID pin);
    Portx(CPinID pin);
    Portx(DPinID pin);
    Portx(EPinID pin);

    /// Read 16 bits of the port simultaneously
    /// @returns 16-bit port value
    uint16_t read(){
        return GPIO_ReadInputData(_base);
    }
    /// Write 16 bits of the port simultaneously
    /// @param 16-bit port value
    void write(uint16_t value){
        GPIO_Write(_base, value);
    }

protected:
    /// GPIO handle structure. Declared in standard peripheral library
    GPIO_TypeDef *_base = nullptr;
};

//Wonderful multiple inheritance could be used for MC with GPIO connected to several buses
template<typename T>
class PinOut: public Portx<T>
{
private:
    void init(){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = Portx<T>::_pin;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(T::_base, &GPIO_InitStructure);
    }

public:
    PinOut(APinID id):Portx<T>{id}{
        init();
    }
    PinOut(BPinID id):Portx<T>{id}{
        init();
    }
    PinOut(CPinID id):Portx<T>{id}{
        init();
    }
    PinOut(DPinID id):Portx<T>{id}{
        init();
    }
    PinOut(EPinID id):Portx<T>{id}{
        init();
    }
};


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
    /// Get current pin state. To be overridden by In and Out subclasses.
    /// @returns bool the pin state
    virtual bool get() = 0;

    /// Cast to bool with current pin state
    /// @returns bool the pin state
    explicit operator bool(){
        return get();
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
    /// Get current pin state
    /// @returns bool the pin state
    virtual bool get() override {
        return static_cast<bool>(GPIO_ReadOutputDataBit(T::_base, Pin<T>::_pin));
    }
    /// Assignment operator
    /// @param value the boolean value of pin state to be set
    /// @returns Pin<T>& returns own reference
    DigitalOut<T>& operator=(const bool value){
        Pin<T>::set(value);
        return *this;
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
    /// Get current pin state
    /// @returns bool the pin state
    virtual bool get() override {
        return static_cast<bool>(GPIO_ReadInputDataBit(T::_base, Pin<T>::_pin));
    }
};
using DigitalInA=DigitalIn<PortA>;
using DigitalInB=DigitalIn<PortB>;
using DigitalInC=DigitalIn<PortC>;
using DigitalInD=DigitalIn<PortD>;
using DigitalInE=DigitalIn<PortE>;

#endif // PIN_H
