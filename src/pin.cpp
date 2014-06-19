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
