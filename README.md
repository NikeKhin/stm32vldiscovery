stm32vldiscovery
================
Hardware abstraction library (HAL) implemented in C++ as a wrapper for Standard Periferal Library provided by ST.
The purpose is to provide simple and self-descriptive interface for periferals and make it possible to start using
it without reading manuals.

Example:
________
`
{
    Dac dac(1);
    dac.write(0);
}
`
