#include "pin.h"

template<>
Pin<APinID>::Pin(APinID id):
    PinBase(static_cast<uint8_t>(id)),
    bus(Bus2()),
    base(GPIOA)
{
    bus->enable(PeripheralID::gpioa);
}
template<>
Pin<BPinID>::Pin(BPinID id):
    PinBase(static_cast<uint8_t>(id)),
    bus(Bus2()),
    base(GPIOB)
{
    bus->enable(PeripheralID::gpiob);
}
template<>
Pin<CPinID>::Pin(CPinID id):
    PinBase(static_cast<uint8_t>(id)),
    bus(Bus2()),
    base(GPIOC)
{
    bus->enable(PeripheralID::gpioc);
}
template<>
Pin<DPinID>::Pin(DPinID id):
    PinBase(static_cast<uint8_t>(id)),
    bus(Bus2()),
    base(GPIOC)
{
    bus->enable(PeripheralID::gpiod);
}
template<>
Pin<EPinID>::Pin(EPinID id):
    PinBase(static_cast<uint8_t>(id)),
    bus(Bus2()),
    base(GPIOD)
{
    bus->enable(PeripheralID::gpioe);
}

