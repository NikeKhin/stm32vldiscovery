#ifndef BUS_H
#define BUS_H

#include "common.h"


/**
    @brief Template class for APB1 and APB2 types.
    @class Bus
 */
template<BusID T>
class Bus
{
    // We may keep some static members here if we need to preserve state
    // I.e. the bus state variables
public:
    /// Default constructor
    Bus()=default;

     /// Start clocking the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    void enable(PeripheralID pid) const;

     /// Stop clocking the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    void disable(PeripheralID pid) const;

     /// Conversion operator
     /// @return Bus*
    //operator const Bus* () const {return this;};
};

template <typename T_busname>
class Device
{
protected:
    Device(PeripheralID pid){
        bus.enable(pid); //TODO: store and disable it in dtor
    };
    static T_busname bus;
};



/*
template<class T>
class Bus{
    static T bus;
public:
    Bus()=default;
    operator const APB* () const {return &(Bus<T>::bus);};
};
*/
using Bus1 = Bus<BusID::APB1>;
using Bus2 = Bus<BusID::APB2>;




#endif // BUS_H
