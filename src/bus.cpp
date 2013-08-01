#include "bus.h"

//TODO: move
extern APB1 bus1;
extern APB2 bus2;


APB1::APB1()
{
}
APB1::~APB1()
{
}
void APB1::enable(PeripheralID id)
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
void APB1::disable(PeripheralID id)
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}



APB2::APB2()
{
}
APB2::~APB2()
{
}
void APB2::enable(PeripheralID id)
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
void APB2::disable(PeripheralID id)
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

