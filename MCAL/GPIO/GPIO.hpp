#pragma once

#include "../../Platform/STM32F103/RCC_MemoryMap.hpp"
#include "../../Services/Bit_Math.hpp"
#include <cstdint>

typedef struct
{
    uintptr_t reg;
    int bit;
} GPIO_t;

enum class Port_t : uint8_t
{
    GPIOA,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF,
    GPIOG
};

enum class Pin_t : uint8_t
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
};

enum class PinMode : uint8_t
{
    Input,
    Output
};

enum class PinDirection : uint8_t
{
    Input,
    Output
};

enum class PinState : uint8_t
{
    Low,
    High
};

class GPIO
{
private:
    GPIO_t GPIOport;

public:
    GPIO();

    void Init(Port_t port);

    uintptr_t GetReg() const;

    int GetBit() const;

    void SetMode(uint8_t Pin, PinMode Mode);

    void SetPin(uint8_t Pin);

    void ClearPin(uint8_t Pin);

    void TogglePin(uint8_t Pin);

    PinState ReadPin(uint8_t Pin);

    void WritePin(uint8_t Pin, PinState State);
};
