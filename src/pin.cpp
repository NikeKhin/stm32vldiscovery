#include "pin.h"


Pin::Pin(APinID id):base(GPIOA)
{
    this->pin = 0x0001 << static_cast<uint8_t>(id);
    bus.enable(PeripheralID::gpioa);
}
Pin::Pin(BPinID id):base(GPIOB)
{
    this->pin = 0x0001 << static_cast<uint8_t>(id);
    bus.enable(PeripheralID::gpiob);
}
Pin::Pin(CPinID id):base(GPIOC)
{
    this->pin = 0x0001 << static_cast<uint8_t>(id);
    bus.enable(PeripheralID::gpioc);
}
Pin::Pin(DPinID id):base(GPIOC)
{
    this->pin = 0x0001 << static_cast<uint8_t>(id);
    bus.enable(PeripheralID::gpiod);
}
Pin::Pin(EPinID id):base(GPIOD)
{
    this->pin = 0x0001 << static_cast<uint8_t>(id);
    bus.enable(PeripheralID::gpioe);
}

void Pin::setupSlowOutAnalog()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(base, &GPIO_InitStructure);
}
void Pin::setupSlowInAnalog()
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = pin;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(base, &GPIO_InitStructure);
}
