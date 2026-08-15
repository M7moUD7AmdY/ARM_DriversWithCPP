#pragma once

#include "../../Platform/STM32F103/RCC_MemoryMap.hpp"
#include "../../Services/Bit_Math.hpp"

template<typename T>
class RCC
{
public:
    static void RCC_InitSysClock();
    static void RCC_Enable_clock(T& peripheral);
    static void RCC_Disable_clock(T& peripheral);
};

