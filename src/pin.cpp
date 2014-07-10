#include "pin.h"

Port::Port(APin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpioa},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOA}
{
    init(mode);
}
Port::Port(BPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpiob},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOB}
{
    init(mode);
}
Port::Port(CPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpioc},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOC}
{
    init(mode);
}
Port::Port(DPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpiod},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOD}
{
    init(mode);
}
Port::Port(EPin pin, GPIOMode_TypeDef mode):
    Device{APB2::gpioe},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOE}
{
    init(mode);
}

