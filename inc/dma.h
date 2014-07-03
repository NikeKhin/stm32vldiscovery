#ifndef DMA_H
#define DMA_H

#include "common.h"
#include "bus.h"

/**
    @class Dma
    @brief Implementation of DMA device

    Possible template parameters AHB
    @param T the bus enum type, containing its peripheral device identifiers (e.g. AHB1 or AHB2)
        @arg AHB1
        @arg AHB2
*/
template<typename T>
class Dma: public Device<T>
{
public:
    Dma();
protected:
    /// DMA handle structure. Declared in standard peripheral library
    DMA_TypeDef *_base = nullptr;
};

#endif // DMA_H
