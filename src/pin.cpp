#include "pin.h"

template<>
Port<APB2,APB2::gpioa>::Port():
    Device(APB2::gpioa),
    base(GPIOA)
{
}

template<>
Port<APB2,APB2::gpiob>::Port():
    Device(APB2::gpiob),
    base(GPIOB)
{
}

template<>
Port<APB2,APB2::gpioc>::Port():
    Device(APB2::gpioc),
    base(GPIOC)
{
}

template<>
Port<APB2,APB2::gpiod>::Port():
    Device(APB2::gpiod),
    base(GPIOD)
{
}

template<>
Port<APB2,APB2::gpioe>::Port():
    Device(APB2::gpioe),
    base(GPIOE)
{
}
