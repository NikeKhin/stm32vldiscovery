#ifndef BUS_H
#define BUS_H

#include "common.h"


/**
  @brief Template class for APB1 and APB2 types.
  Possible template parameters BusID::APB1 and BusID::APB2
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
};


using Bus1 = Bus<BusID::APB1>;
using Bus2 = Bus<BusID::APB2>;


/**
    @brief Protected constructor enables the device
    Possible template parameters Bus1 and Bus2 (see 'using' clause above)
*/
template <PeripheralID pid, typename T_busname>
class Device
{
private:
    /// Peripheral ID (one of DAC, ADC, TIM, GPIO etc.)
    PeripheralID _pid = {pid};

protected:
    /**
      @brief Protected constructor enables the device
    */
    Device(){
        bus.enable(_pid);
    };
    ~Device(){
        bus.disable(_pid);
    }
    T_busname bus;//TODO: find a way to make it static?
};




#endif // BUS_H
