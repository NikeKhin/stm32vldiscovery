#include "pin.h"

Port::Port(APin pin, GPIOMode_TypeDef mode):
    Device{gpioa},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOA}
{
    init(mode);
}
Port::Port(BPin pin, GPIOMode_TypeDef mode):
    Device{gpiob},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOB}
{
    init(mode);
}
Port::Port(CPin pin, GPIOMode_TypeDef mode):
    Device{gpioc},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOC}
{
    init(mode);
}
Port::Port(DPin pin, GPIOMode_TypeDef mode):
    Device{gpiod},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOD}
{
    init(mode);
}
Port::Port(EPin pin, GPIOMode_TypeDef mode):
    Device{gpioe},
    _pin{static_cast<uint16_t>(pin)},
    _base{GPIOE}
{
    init(mode);
}

