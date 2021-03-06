stm32vldiscovery C++ template based HAL
================
Hardware abstraction library (HAL) implemented in C++ as a wrapper for Standard Peripheral Library (SPL) aka Standard Firmware Library provided by ST.
The purpose is to provide simple and self-descriptive interface for peripherals and make it possible to start using it without reading manuals.

The library has static resource allocation and small footprint.

Interface is loosely similar to [mbed Microcontroller Library](https://mbed.org/handbook/mbed-SDK).

See additional information in Russian [in the blog](https://c4arm.blogspot.com/)

Example:
--------------------

```C++

int main()
{
    PinOut green(c9);          // output pin to light green LED
    PinOut blue(CPin::c8);     // this pin wired to blue LED
    PinIn button(a0);          // this pin connected to user button (blue one) in read mode

    green = true;
    blue = false;

    Analog converter(adc1);
    Analog::in1 left_channel(converter);
    Analog::in2 right_channel(converter);

    converter.start();

    while (1)
    {
        // read two ADC channels in cycle
        int p = left_channel.read();
        int q = right_channel.read();
        // pause blinking when button is pressed
        if(button.get())
            wait(1_s);
        // toggle LEDs
        green=!green;
        blue.toggle(); // explicit way to toggle LED
        // insert delay
        wait(500_ms);
    }
    return 0;
}

```


Current SPL libraries
--------------------
F1:
STSW-STM32078 STM32VLDISCOVERY firmware package (AN3268)
http://www.st.com/web/en/catalog/tools/PF257914
v 1.0.0

L1:
STSW-STM32072 STM32L1 Discovery firmware package (RN0079)
http://www.st.com/web/en/catalog/tools/PF257908
v 1.0.3

F3:
STSW-STM32118 STM32F3 Discovery kit firmware package
http://www.st.com/web/en/catalog/tools/PF258154
v 1.1.0

F4:
STSW-STM32068 STM32F4DISCOVERY (STM32F407VG MCU) board firmware package (AN3983)
http://www.st.com/web/en/catalog/tools/PF257904
v 1.1.0
STSW-STM32138 STM32F429 discovery (STM32F429ZI MCU) firmware package (UM1662)
http://www.st.com/web/en/catalog/tools/PF259429
v1.0.1
STSW-STM32136 STM32F401 discovery (STM32F401VC MCU) firmware package (UM1660)
http://www.st.com/web/en/catalog/tools/PF259428


Official documentation and samples
--------------------
STSW-STM32028 STM32's ADC modes and their applications (AN3116)
http://www.st.com/web/en/catalog/tools/PF257864
1.0


License information
--------------------
mbed Microcontroller Library - http://www.apache.org/licenses/LICENSE-2.0
