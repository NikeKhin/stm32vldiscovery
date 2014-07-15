#ifndef LED_H
#define LED_H

#include "common.h"

//---------------------------------
class Led
{
public:
    //Led(LedID led);
    void on();
    void off();
    void toggle();
protected:
    //Led_TypeDef base;
};

#endif // LED_H
