#include "pin.h"

template<>
Port<APB2,APB2::gpioa>::Port():
    Device {APB2::gpioa},
    _base {GPIOA}
{
}

template<>
Port<APB2,APB2::gpiob>::Port():
    Device {APB2::gpiob},
    _base {GPIOB}
{
}

template<>
Port<APB2,APB2::gpioc>::Port():
    Device{APB2::gpioc},
    _base{GPIOC}
{
}

template<>
Port<APB2,APB2::gpiod>::Port():
    Device{APB2::gpiod},
    _base{GPIOD}
{
}

template<>
Port<APB2,APB2::gpioe>::Port():
    Device{APB2::gpioe},
    _base{GPIOE}
{
}
//-----
template<>
Portx<APB2>::Portx(APinID pin):
    Device{APB2::gpioa},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOA}
{
}
template<>
Portx<APB2>::Portx(BPinID pin):
    Device{APB2::gpiob},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOB}
{
}
template<>
Portx<APB2>::Portx(CPinID pin):
    Device{APB2::gpioc},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOC}
{
}
template<>
Portx<APB2>::Portx(DPinID pin):
    Device{APB2::gpiod},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOD}
{
}
template<>
Portx<APB2>::Portx(EPinID pin):
    Device{APB2::gpioe},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOE}
{
}
