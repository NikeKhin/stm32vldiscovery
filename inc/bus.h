#ifndef BUS_H
#define BUS_H

#include "common.h"


/**
  @class Bus
  @brief Template class for APB1 and APB2 bus types.

  Possible template parameters APB1 and APB2 enumerations (see common.h)
 */
template<typename T>
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
    void enable(T pid) const;

     /// Stop clocking the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    void disable(T pid) const;
};



/**
    @class Device
    @brief Protected constructor enables the device

    Device aggregates Bus member of proper bus number
    Possible template parameters APB1 and APB2 enumerations (see common.h)
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
*/
template <typename T>
class Device
{
    Device() = delete;
    Device(const Device& value)=delete;
    Device& operator=(const Device& value)=delete;

private:
    /// Peripheral ID (one of DAC, ADC, TIM, GPIO etc.)
    T _pid;

    /// The bus to which the device is attached
    Bus<T> _bus;//TODO: find a way to make it static?
protected:
    /// Protected constructor internally enables the device
    /// @param pid a peripheral ID enumerated value
    Device(T pid):_pid{pid}{
        _bus.enable(_pid);
    };
    /// Protected destructor invoked by inheritance order
    ~Device(){
        _bus.disable(_pid);
    }

};




#endif // BUS_H
