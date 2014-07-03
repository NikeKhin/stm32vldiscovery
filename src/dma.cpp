#include "dma.h"

template<>
Dma<AHB>::Dma():
    Device{AHB::dma1},
    _base{DMA1}
{
}

