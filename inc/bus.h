#ifndef BUS_H
#define BUS_H

#include "common.h"

//--------------------------------------
class APB
{
public:
    virtual void enable(PeripheralID) const = 0;
    virtual void disable(PeripheralID) const  = 0;
};
//--------------------------------------
class APB1 : public APB
{
public:
    APB1() = default;
    virtual ~APB1() = default;
    void enable(PeripheralID) const;
    void disable(PeripheralID) const;
};
//--------------------------------------
class APB2 : public APB
{
public:
    APB2() = default;
    virtual ~APB2() = default;
    void enable(PeripheralID) const;
    void disable(PeripheralID) const;
};

template<class T>
class Bus{
    static T bus;
public:
    Bus()=default;
    operator const APB* () const {return &this->bus;};
};

#endif // BUS_H
