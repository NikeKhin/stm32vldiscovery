stm32vldiscovery
================
Hardware abstraction library (HAL) implemented in C++ as a wrapper for Standard Peripheral Library (SPL) aka Standard Firmware Library provided by ST.
The purpose is to provide simple and self-descriptive interface for peripherals and make it possible to start using it without reading manuals.

Interface is loosely similar to [mbed Microcontroller Library](https://mbed.org/handbook/mbed-SDK).

See additional information in Russian [in the blog](https://c4arm.blogspot.com/)

Example:
________
```C++
{
    Dac dac(1);
    dac.write(0);
}
```
Current SPL libraries
==================
STSW-STM32078 STM32VLDISCOVERY firmware package (AN3268)
http://www.st.com/web/en/catalog/tools/PF257914
v 1.0.0

STSW-STM32072 STM32L1 Discovery firmware package (RN0079)
http://www.st.com/web/en/catalog/tools/PF257908
v 1.0.3

STSW-STM32118 STM32F3 Discovery kit firmware package
http://www.st.com/web/en/catalog/tools/PF258154
v 1.1.0

STSW-STM32068 STM32F4DISCOVERY (STM32F407VG MCU) board firmware package (AN3983)
http://www.st.com/web/en/catalog/tools/PF257904
v 1.1.0
STSW-STM32138 STM32F429 discovery (STM32F429ZI MCU) firmware package (UM1662)
http://www.st.com/web/en/catalog/tools/PF259429
v1.0.1
STSW-STM32136 STM32F401 discovery (STM32F401VC MCU) firmware package (UM1660)
http://www.st.com/web/en/catalog/tools/PF259428

Official documentation and samples
==================
STSW-STM32028 STM32's ADC modes and their applications (AN3116)
http://www.st.com/web/en/catalog/tools/PF257864
1.0


License information
==================
mbed Microcontroller Library - http://www.apache.org/licenses/LICENSE-2.0
