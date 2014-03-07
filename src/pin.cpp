#include "pin.h"

template<>
Port<PeripheralID::gpioa,Bus2>::Port():
    base(GPIOA)
{
}

template<>
Port<PeripheralID::gpiob,Bus2>::Port():
    base(GPIOB)
{
}

template<>
Port<PeripheralID::gpioc,Bus2>::Port():
    base(GPIOC)
{
}

template<>
Port<PeripheralID::gpiod,Bus2>::Port():
    base(GPIOD)
{
}

template<>
Port<PeripheralID::gpioe,Bus2>::Port():
    base(GPIOE)
{
}
