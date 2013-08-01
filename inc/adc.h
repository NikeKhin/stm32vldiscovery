#ifndef ADC_H
#define ADC_H

#include "common.h"
#include "bus.h"
#include "pin.h"


//---------------------------------
class ADConverter
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};


class ADConverter1:public ADConverter
{
public:
    ADConverter1();
    virtual ~ADConverter1();
    void start();
    void stop();
    uint16_t read();
protected:
    ADC_TypeDef* base = nullptr;
    APB &bus;
    Pin pin;
};

#endif // ADC_H
