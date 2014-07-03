#include "pin.h"

template<>
Portx<APB2>::Portx(APin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpioa},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOA}
{
    init(mode);
}
template<>
Portx<APB2>::Portx(BPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpiob},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOB}
{
    init(mode);
}
template<>
Portx<APB2>::Portx(CPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpioc},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOC}
{
    init(mode);
}
template<>
Portx<APB2>::Portx(DPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpiod},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOD}
{
    init(mode);
}
template<>
Portx<APB2>::Portx(EPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpioe},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOE}
{
    init(mode);
}

