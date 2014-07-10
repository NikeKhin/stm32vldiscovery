#ifndef PIN_H
#define PIN_H

#include "common.h"
#include "bus.h"

/**
    @class Portx
    @brief Implementation of GPIO port (16-bit)

    Possible template parameters APB1 or APB2
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
        @arg APB1
        @arg APB2
*/
class Port: public Device
{
protected:
    /// Specialized protected constructors.
    /// @param pin a pin name from strongly typed enumeration
    Port(APin pin, GPIOMode_TypeDef mode);
    Port(BPin pin, GPIOMode_TypeDef mode);
    Port(CPin pin, GPIOMode_TypeDef mode);
    Port(DPin pin, GPIOMode_TypeDef mode);
    Port(EPin pin, GPIOMode_TypeDef mode);

public:
    /// Read 16 bits of the port simultaneously
    /// @returns 16-bit port value
    uint16_t read(){
        return GPIO_ReadInputData(_base);
    }
    /// Write 16 bits of the port simultaneously
    /// @param value 16-bit port value
    void write(uint16_t value){
        GPIO_Write(_base, value);
    }
    /// Pure virtual to get current pin state
    /// @returns bool the pin state
    virtual bool get() = 0;

    /// Set/reset current pin value
    /// @param value the boolean value of the set pin state
    void set(bool value){
        GPIO_WriteBit(_base, _pin, value?Bit_SET:Bit_RESET);
    }
    /// Set current pin value
    void on(){
        GPIO_WriteBit(_base, _pin, Bit_SET);
    }
    /// Reset current pin value
    void off(){
        GPIO_WriteBit(_base, _pin, Bit_RESET);
    }
    /// Invert pin state
    void toggle(){
        set(!get());
    }
protected:
    /// GPIO handle structure. Declared in standard peripheral library
    GPIO_TypeDef *_base = nullptr;
    /// The set bit on the bit position of the pin number
    uint16_t _pin;
private:
    void init(GPIOMode_TypeDef mode){
        GPIO_InitTypeDef GPIO_InitStructure;
        GPIO_InitStructure.GPIO_Pin = _pin;
        GPIO_InitStructure.GPIO_Mode = mode;
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
        GPIO_Init(_base, &GPIO_InitStructure);
    }
};

/**
    @class PinOutX
    @brief Specific pin of a 16-bit GPIO port configured to be digital output push-pull mode

    Possible template parameters APB1 or APB2
    Wonderful multiple inheritance could be used for MC with GPIO connected to several buses.
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
        @arg APB1
        @arg APB2
*/
class PinOut: public Port
{
public:
    PinOut(APin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Port{id,mode}{}
    PinOut(BPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Port{id,mode}{}
    PinOut(CPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Port{id,mode}{}
    PinOut(DPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Port{id,mode}{}
    PinOut(EPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Port{id,mode}{}
    /// Get current pin state
    /// @returns bool the pin state
    virtual bool get() override {
        return static_cast<bool>(GPIO_ReadOutputDataBit(Port::_base, Port::_pin));
    }
    /// Cast to bool with current pin state
    /// @returns bool the pin state
    explicit operator bool(){
        return get();
    }
    /// Assignment operator
    /// @param value the boolean value of pin state to be set
    /// @returns PinOutX<T>& returns own reference
    PinOut& operator=(const bool value){
        Port::set(value);
        return *this;
    }
};


/**
    @class PinInX
    @brief Specific pin of a 16-bit GPIO port configured to be digital output push-pull mode

    Possible template parameters APB1 or APB2
    Wonderful multiple inheritance could be used for MC with GPIO connected to several buses.
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
        @arg APB1
        @arg APB2
*/
class PinIn: public Port
{
public:
    PinIn(APin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Port{id,mode}{}
    PinIn(BPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Port{id,mode}{}
    PinIn(CPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Port{id,mode}{}
    PinIn(DPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Port{id,mode}{}
    PinIn(EPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Port{id,mode}{}
    /// Get current pin state
    /// @returns bool the pin state
    virtual bool get() override {
        return static_cast<bool>(GPIO_ReadInputDataBit(Port::_base, Port::_pin));
    }
    /// Cast to bool with current pin state
    /// @returns bool the pin state
    explicit operator bool(){
        return get();
    }
    /// Assignment operator
    /// @param value the boolean value of pin state to be set
    /// @returns PinInX<T>& returns own reference
    PinIn& operator=(const bool value){
        Port::set(value);
        return *this;
    }
};


#endif // PIN_H
