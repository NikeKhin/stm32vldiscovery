#ifndef BUS_H
#define BUS_H

#include "common.h"

/**
    @brief Pure vitrual class with interface methods for APB.
    @class APB
    Base class for APB1 and APB2 types.
 */
class APB
{
public:
     /// Start clocking virtual method
     /// @param pid - peripheral device identifier
     /// @return void
    virtual void enable(PeripheralID pid) const = 0;

     /// Stop clocking virtual method
     /// @param pid - peripheral device identifier
     /// @return void
    virtual void disable(PeripheralID pid) const  = 0;
};

class APB1 : public APB
{
public:
    APB1() = default;
    virtual ~APB1() = default;
    void enable(PeripheralID) const;
    void disable(PeripheralID) const;
};

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
    operator const APB* () const {return &(Bus<T>::bus);};
};

using Bus1 = Bus<APB1>;
using Bus2 = Bus<APB2>;

#endif // BUS_H
