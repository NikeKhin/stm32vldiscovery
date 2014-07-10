#ifndef BUS_H
#define BUS_H

#include "common.h"


class Bus
{
public:
    virtual void enable(AHB pid)  {};
    virtual void enable(APB1 pid)  {};
    virtual void enable(APB2 pid)  {};
    virtual void disable() const {};
    virtual void reset() const {};
};

/**
  @class Bus
  @brief Template class for APB1 and APB2 bus types.

  Possible template parameters APB1 and APB2 enumerations (see common.h)
 */
template<typename T>
class BusX : public Bus
{
public:
    /// Default constructor
    BusX()=default;

     /// Start clocking the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    //template<typename T>
    void enable(T pid) override;

     /// Stop clocking the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    //template<typename T>
    void disable() const override;

     /// Reset the peripheral device identified by PID
     /// @param pid - peripheral device identifier
     /// @return void
    //template<typename T>
    void reset() const override;

private:
    /// Peripheral ID (one of DAC, ADC, TIM, GPIO etc.)
    T _pid;

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

private:
    /// Peripheral ID (one of DAC, ADC, TIM, GPIO etc.)
    //uint32_t _pid;

    /// The bus to which the device is attached
    Bus _attachement;
protected:
    /// Protected constructor internally enables the device
    /// @param pid a peripheral ID enumerated value
    Device(APB1 pid):_attachement{BusX<APB1>()}{
        _attachement.enable(pid);
    };
    Device(APB2 pid):_attachement{BusX<APB2>()}{
        _attachement.enable(pid);
    };
    Device(AHB pid):_attachement{BusX<AHB>()}{
        _attachement.enable(pid);
    };
    /// Protected destructor invoked by inheritance order
    ~Device(){
        _attachement.disable();
    }

};




#endif // BUS_H
