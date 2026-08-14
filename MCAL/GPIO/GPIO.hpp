#pragma once

#include "../../Platform/STM32F103/MemoryMap.hpp"
#include "../../Services/Bit_Math.hpp"

typedef struct
{
    int reg;
    int bit;
} GPIO_t;

enum class Port_t
{
    GPIOA,
    GPIOB
};

class GPIO
{
private:
    GPIO_t GPIOport;

public:
    GPIO();
    void Init(Port_t port);

    int GetReg() const;
    int GetBit() const;
};