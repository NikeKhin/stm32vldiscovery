#include "bus.h"

template<>
void BusX<AHB>::enable(AHB id)
{
    _pid = id;
    RCC_AHBPeriphClockCmd(static_cast<uint32_t>(_pid), ENABLE);
}
template<>
void BusX<AHB>::disable() const
{
    RCC_AHBPeriphClockCmd(static_cast<uint32_t>(_pid), DISABLE);
}
template<>
void BusX<AHB>::reset() const
{
    RCC_AHBPeriphClockCmd(static_cast<uint32_t>(_pid), DISABLE);
    RCC_AHBPeriphClockCmd(static_cast<uint32_t>(_pid), ENABLE);
}


template<>
void BusX<APB1>::enable(APB1 id)
{
    _pid = id;
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(_pid), ENABLE);
}
template<>
void BusX<APB1>::disable() const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(_pid), DISABLE);
}
template<>
void BusX<APB1>::reset() const
{
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(_pid), DISABLE);
    RCC_APB1PeriphClockCmd(static_cast<uint32_t>(_pid), ENABLE);
}

template<>
void BusX<APB2>::enable(APB2 id)
{
    _pid = id;
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(_pid), ENABLE);
}
template<>
void BusX<APB2>::disable() const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(_pid), DISABLE);
}
template<>
void BusX<APB2>::reset() const
{
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(_pid), DISABLE);
    RCC_APB2PeriphClockCmd(static_cast<uint32_t>(_pid), ENABLE);
}

