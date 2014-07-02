#include "pin.h"

template<>
Portx<APB2>::Portx(APin pin):
    Device{APB2::gpioa},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOA}
{
}
template<>
Portx<APB2>::Portx(BPin pin):
    Device{APB2::gpiob},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOB}
{
}
template<>
Portx<APB2>::Portx(CPin pin):
    Device{APB2::gpioc},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOC}
{
}
template<>
Portx<APB2>::Portx(DPin pin):
    Device{APB2::gpiod},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOD}
{
}
template<>
Portx<APB2>::Portx(EPin pin):
    Device{APB2::gpioe},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOE}
{
}

