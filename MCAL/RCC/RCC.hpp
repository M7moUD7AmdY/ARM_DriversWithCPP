#pragma once

#include "../../Platform/STM32F103/MemoryMap.hpp"
#include "../../Services/Bit_Math.hpp"

template<typename T>
class RCC
{


    public:
    static void RCC_InitSysClock();
    static void RCC_Enable_clock(T &Prephral);
    static void RCC_Disable_clock(T &Prephral);

};


