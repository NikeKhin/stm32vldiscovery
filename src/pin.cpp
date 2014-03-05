#include "pin.h"

template<>
Port<PeripheralID::gpioa,Bus2>::Port(PeripheralID pid):
    Device<Bus2>(pid),
    base(GPIOA)
{
}
