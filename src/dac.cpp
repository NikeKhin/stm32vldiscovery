#include "dac.h"

//TODO: move
extern APB1 bus1;
extern APB2 bus2;

Dac1::Dac1():bus(bus1),base(DAC),tim()
{
    bus.enable(PeripheralID::dac);
    pin.setupSlowOutAnalog();
}
Dac1::~Dac1()
{
    DAC_DeInit();
}

void Dac1::start()
{
    DAC_Cmd(DAC_Channel_1,ENABLE);
    //DAC->CR |= DAC_CR_EN1;
}
void Dac1::stop()
{
}



static int16_t value = 4095;
static float temperatureC = 0;

void Dac::tick()
{
    //Reset UIF
    TIM6->SR &= ~TIM_SR_UIF;


    DAC->DHR12R1=value;

    value -= 100 + temperatureC*8.0;
    if(value < 100)
        value = 4095;
}
