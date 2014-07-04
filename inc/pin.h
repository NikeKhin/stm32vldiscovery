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
template<typename T>
class Portx: public Device<T>
{
protected:
    /// Specialized protected constructors.
    /// @param pin a pin name from strongly typed enumeration
    Portx(APin pin, GPIOMode_TypeDef mode);
    Portx(BPin pin, GPIOMode_TypeDef mode);
    Portx(CPin pin, GPIOMode_TypeDef mode);
    Portx(DPin pin, GPIOMode_TypeDef mode);
    Portx(EPin pin, GPIOMode_TypeDef mode);

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
template<typename T>
class PinOutX: public Portx<T>
{
public:
    PinOutX(APin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Portx<T>{id,mode}{}
    PinOutX(BPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Portx<T>{id,mode}{}
    PinOutX(CPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Portx<T>{id,mode}{}
    PinOutX(DPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Portx<T>{id,mode}{}
    PinOutX(EPin id, GPIOMode_TypeDef mode=GPIO_Mode_Out_PP):Portx<T>{id,mode}{}
    /// Get current pin state
    /// @returns bool the pin state
    virtual bool get() override {
        return static_cast<bool>(GPIO_ReadOutputDataBit(Portx<T>::_base, Portx<T>::_pin));
    }
    /// Cast to bool with current pin state
    /// @returns bool the pin state
    explicit operator bool(){
        return get();
    }
    /// Assignment operator
    /// @param value the boolean value of pin state to be set
    /// @returns PinOutX<T>& returns own reference
    PinOutX<T>& operator=(const bool value){
        Portx<T>::set(value);
        return *this;
    }
};
using PinOut=PinOutX<APB2>;


/**
    @class PinInX
    @brief Specific pin of a 16-bit GPIO port configured to be digital output push-pull mode

    Possible template parameters APB1 or APB2
    Wonderful multiple inheritance could be used for MC with GPIO connected to several buses.
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
        @arg APB1
        @arg APB2
*/
template<typename T>
class PinInX: public Portx<T>
{
public:
    PinInX(APin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Portx<T>{id,mode}{}
    PinInX(BPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Portx<T>{id,mode}{}
    PinInX(CPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Portx<T>{id,mode}{}
    PinInX(DPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Portx<T>{id,mode}{}
    PinInX(EPin id, GPIOMode_TypeDef mode=GPIO_Mode_IN_FLOATING):Portx<T>{id,mode}{}
    /// Get current pin state
    /// @returns bool the pin state
    virtual bool get() override {
        return static_cast<bool>(GPIO_ReadInputDataBit(Portx<T>::_base, Portx<T>::_pin));
    }
    /// Cast to bool with current pin state
    /// @returns bool the pin state
    explicit operator bool(){
        return get();
    }
    /// Assignment operator
    /// @param value the boolean value of pin state to be set
    /// @returns PinInX<T>& returns own reference
    PinInX<T>& operator=(const bool value){
        Portx<T>::set(value);
        return *this;
    }
};
using PinIn=PinInX<APB2>;



#endif // PIN_H
