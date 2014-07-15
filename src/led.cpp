#include "led.h"


/*
Led::Led(LedID led)
{
    if(led==LedID::blue)
        base = LED3;
    else
        base = LED4;
    STM32vldiscovery_LEDInit(base);
}    */

void Led::on()
{
    //STM32vldiscovery_LEDOn(base);
}
void Led::off()
{
    //STM32vldiscovery_LEDOff(base);
}
void Led::toggle()
{
    //STM32vldiscovery_LEDToggle(base);
}
