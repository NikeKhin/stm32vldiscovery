#ifndef BUS_H
#define BUS_H

#include "common.h"

//--------------------------------------
// Declare two objects of correspondingly APB1 and APB2 classes
class APB1;
class APB2;
extern APB1 bus1;
extern APB2 bus2;

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
    APB1() = default;
    virtual ~APB1() = default;
    void enable(PeripheralID);
    void disable(PeripheralID);
};
//--------------------------------------
class APB2 : public APB
{
public:
    APB2() = default;
    virtual ~APB2() = default;
    void enable(PeripheralID);
    void disable(PeripheralID);
};

#endif // BUS_H
