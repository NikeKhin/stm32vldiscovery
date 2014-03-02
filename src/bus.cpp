#include "bus.h"

/*
template<>
APB1 Bus1::bus = APB1();

template<>
APB2 Bus2::bus = APB2();
*/
template<>
void Bus1::enable(PeripheralID id) const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
template<>
void Bus1::disable(PeripheralID id) const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

template<>
void Bus2::enable(PeripheralID id) const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
template<>
void Bus2::disable(PeripheralID id) const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

