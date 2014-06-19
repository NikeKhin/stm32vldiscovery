#include "bus.h"

//TODO: add AHP device

template<>
void Bus<APB1>::enable(APB1 id) const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
template<>
void Bus<APB1>::disable(APB1 id) const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

template<>
void Bus<APB2>::enable(APB2 id) const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), ENABLE);
}
template<>
void Bus<APB2>::disable(APB2 id) const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(id), DISABLE);
}

