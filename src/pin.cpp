#include "pin.h"

template<>
Port<PeripheralID::gpioa>::Port():
    Device(PeripheralID::gpioa),
    base(GPIOA)
{
}

template<>
Port<PeripheralID::gpiob>::Port():
    Device(PeripheralID::gpiob),
    base(GPIOB)
{
}

template<>
Port<PeripheralID::gpioc>::Port():
    Device(PeripheralID::gpioc),
    base(GPIOC)
{
}

template<>
Port<PeripheralID::gpiod>::Port():
    Device(PeripheralID::gpiod),
    base(GPIOD)
{
}

template<>
Port<PeripheralID::gpioe>::Port():
    Device(PeripheralID::gpioe),
    base(GPIOE)
{
}
