#include "bus.h"

//TODO: move
APB1 bus1;
APB2 bus2;


void APB1::enable(PeripheralID id)
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
void APB1::disable(PeripheralID id)
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}


void APB2::enable(PeripheralID id)
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
void APB2::disable(PeripheralID id)
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

