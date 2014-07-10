#ifndef BUS_H
#define BUS_H

#include "common.h"

/**
  @class Bus
  @brief Class for APB1 and APB2 bus types.
 */
class ClockIt
{
public:
    /// Overloaded constructor
    ClockIt(APB1 pid):_apb1_pid{pid},_apb2_pid(),_ahb_pid(){
        RCC_APB1PeriphClockCmd(static_cast<uint32_t>(pid), ENABLE);
    }
    ClockIt(APB2 pid):_apb2_pid{pid},_apb1_pid(),_ahb_pid(){
        RCC_APB2PeriphClockCmd(static_cast<uint32_t>(pid), ENABLE);
    }
    ClockIt(AHB pid):_ahb_pid{pid},_apb1_pid(),_apb2_pid(){
        RCC_AHBPeriphClockCmd(static_cast<uint32_t>(pid), ENABLE);
    }

    /// The solution to use all functions at once was chosen to avoid
    /// using template parameters in user code
    ~ClockIt(){
        if(_apb1_pid){
            RCC_APB1PeriphClockCmd(static_cast<uint32_t>(_apb1_pid), DISABLE);
        }
        else if(_apb2_pid){
            RCC_APB2PeriphClockCmd(static_cast<uint32_t>(_apb2_pid), DISABLE);
        }
        else if(_ahb_pid){
            RCC_AHBPeriphClockCmd(static_cast<uint32_t>(_ahb_pid), DISABLE);
        }

    }
private:
    /// Peripheral ID (one of DAC, ADC, TIM, GPIO etc.)
    APB1 _apb1_pid;
    APB2 _apb2_pid;
    AHB  _ahb_pid;

};



/**
    @class Device
    @brief Protected constructor enables the device

    Device aggregates Bus member of proper bus number
    Possible template parameters APB1 and APB2 enumerations (see common.h)
    @param T the bus enum type, containing its peripheral device identifiers (e.g. APB1 or APB2)
*/
class Device
{
    Device() = delete;
    Device(const Device& value)=delete;
    Device& operator=(const Device& value)=delete;

protected:
    /// Protected constructor internally enables the device
    /// @param pid a peripheral ID enumerated value
    Device(APB1 pid):_clock{pid}{
    };
    Device(APB2 pid):_clock{pid}{
    };
    Device(AHB pid):_clock{pid}{
    };
    /// Protected destructor invoked in inheritance order
    ~Device(){
    }
private:
    /// The bus to which the device is attached
    ClockIt _clock;
};




#endif // BUS_H
