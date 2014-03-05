#include "pin.h"

template<>
Port<PeripheralID::gpioa,Bus2>::Port(PeripheralID pid):
    Device<Bus2>(pid),
    base(GPIOA)
{
}

template<>
Port<PeripheralID::gpiob,Bus2>::Port(PeripheralID pid):
    Device<Bus2>(pid),
    base(GPIOB)
{
}

template<>
Port<PeripheralID::gpioc,Bus2>::Port(PeripheralID pid):
    Device<Bus2>(pid),
    base(GPIOC)
{
}

template<>
Port<PeripheralID::gpiod,Bus2>::Port(PeripheralID pid):
    Device<Bus2>(pid),
    base(GPIOD)
{
}

template<>
Port<PeripheralID::gpioe,Bus2>::Port(PeripheralID pid):
    Device<Bus2>(pid),
    base(GPIOE)
{
}
