stm32vldiscovery
================
Hardware abstraction library (HAL) implemented in C++ as a wrapper for Standard Peripheral Library (SPL) aka Standard Firmware Library provided by ST.
The purpose is to provide simple and self-descriptive interface for peripherals and make it possible to start using it without reading manuals.

Example:
________
`
{
    Dac dac(1);
    dac.write(0);
}
`
Current SPL libraries
==================
STSW-STM32078 STM32VLDISCOVERY firmware package (AN3268)
http://www.st.com/web/en/catalog/tools/PF257914
v 1.0.0

STSW-STM32068 STM32F4DISCOVERY board firmware package (AN3983)
http://www.st.com/web/en/catalog/tools/PF257904
v 1.1.0

STSW-STM32072 STM32L1 Discovery firmware package (RN0079)
http://www.st.com/web/en/catalog/tools/PF257908
v 1.0.3

STSW-STM32118 STM32F3 Discovery kit firmware package
http://www.st.com/web/en/catalog/tools/PF258154
v 1.1.0
