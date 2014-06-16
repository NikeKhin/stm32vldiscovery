stm32vldiscovery
================
Hardware abstraction library (HAL) implemented in C++ as a wrapper for Standard Peripheral Library provided by ST.
The purpose is to provide simple and self-descriptive interface for peripherals and make it possible to start using
it without reading manuals.

Example:
________
`
{
    Dac dac(1);
    dac.write(0);
}
`
Current STM libraries
==================
STSW-STM32078 STM32VLDISCOVERY firmware package (AN3268)
http://www.st.com/web/en/catalog/tools/PF257914

STSW-STM32068STM32F4DISCOVERY board firmware package (AN3983)
http://www.st.com/web/en/catalog/tools/PF257904

