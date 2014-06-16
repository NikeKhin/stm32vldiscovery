#ifndef BUS_H
#define BUS_H

#include "common.h"


/**
  @brief Template class for APB1 and APB2 types.
  Possible template parameters BusID::APB1 and BusID::APB2
  @class Bus
 */
class BusBase
{
    // We may keep some static members here if we need to preserve state
    // I.e. the bus state variables
public:
    /// Default constructor
    BusBase()=default;

     /// Start clocking the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    virtual void enable(PeripheralID pid) const {};

     /// Stop clocking the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    virtual void disable(PeripheralID pid) const {};
};

// Templated version for each bus present in a system. Each version is specialized.
template<BusID T>
class Bus:public BusBase{
    virtual void enable(PeripheralID pid) const;
    virtual void disable(PeripheralID pid) const;
};

// Specialized versions
using Bus1 = Bus<BusID::APB1>;
using Bus2 = Bus<BusID::APB2>;


/**
    @brief Protected constructor enables the device
    Possible template parameters Bus1 and Bus2 (see 'using' clause above)
*/
class Device
{
public:
    Device() = delete;

private:
    /// Peripheral ID (one of DAC, ADC, TIM, GPIO etc.)
    PeripheralID _pid;
    const BusBase &_bus;//TODO: find a way to make it static?
protected:
    /**
      @brief Protected constructor enables the device
    */
    template <typename Tid>
    Device(Tid pid):_pid{pid},_bus{Bus1{}}{
        _bus.enable(_pid);
    };
    ~Device(){
        _bus.disable(_pid);
    }

};




#endif // BUS_H
