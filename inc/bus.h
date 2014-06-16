#ifndef BUS_H
#define BUS_H

#include "common.h"


/**
  @brief Template class for APB1 and APB2 types.
  Possible template parameters APB1 and APB2
  @class Bus
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
    @brief Protected constructor enables the device
    Possible template parameters Bus1 and Bus2 (see 'using' clause above)
*/
template <typename T>
class Device
{
    Device() = delete;
private:
    /// Peripheral ID (one of DAC, ADC, TIM, GPIO etc.)
    T _pid;
    Bus<T> _bus;//TODO: find a way to make it static?
protected:
    /**
      @brief Protected constructor enables the device
    */
    Device(T pid):_pid{pid}{
        _bus.enable(_pid);
    };
    ~Device(){
        _bus.disable(_pid);
    }

};




#endif // BUS_H
