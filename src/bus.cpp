#include "bus.h"


template<>
APB2 Bus<APB2>::bus = APB2();

template<>
APB1 Bus<APB1>::bus = APB1();

void APB1::enable(PeripheralID id) const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
void APB1::disable(PeripheralID id) const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

void APB2::enable(PeripheralID id) const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
void APB2::disable(PeripheralID id) const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

