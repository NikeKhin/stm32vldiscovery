#ifndef BUS_H
#define BUS_H

#include "common.h"

//--------------------------------------
class APB
{
public:
    virtual void enable(PeripheralID) = 0;
    virtual void disable(PeripheralID) = 0;
};
//--------------------------------------
class APB1 : public APB
{
public:
    APB1();
    virtual ~APB1();
    void enable(PeripheralID);
    void disable(PeripheralID);
};
//--------------------------------------
class APB2 : public APB
{
public:
    APB2();
    virtual ~APB2();
    void enable(PeripheralID);
    void disable(PeripheralID);
};

#endif // BUS_H
