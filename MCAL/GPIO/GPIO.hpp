#pragma once

#include "../../Platform/STM32F103/RCC_MemoryMap.hpp"
#include "../../Platform/STM32F103/GPIO_MemoryMap.hpp"
#include "../../Services/Bit_Math.hpp"
#include <cstdint>

typedef struct
{
    // RCC
    uintptr_t RCC_reg;
    uint32_t RCC_bit;

    // GPIO registers
    uintptr_t CRL;
    uintptr_t CRH;
    uintptr_t IDR;
    uintptr_t ODR;
    uintptr_t BSRR;
    uintptr_t BRR;

} GPIO_t;

enum class Port_t : uint8_t
{
    GPIOA=0,
    GPIOB,
    GPIOC,
};

enum class Pin_t : uint8_t
{
    PIN0=0,
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
    Input=0,
    Output
};


enum class PinState : uint8_t
{
    Low=0,
    High
};

enum class GPIO_Mode : uint8_t
{
    Input_Analog       = 0b0000,
    Output_PP_10MHz    = 0b0001,
    Output_PP_2MHz     = 0b0010,
    Output_PP_50MHz    = 0b0011,
    Input_Floating     = 0b0100,
    Output_OD_10MHz    = 0b0101,
    Output_OD_2MHz     = 0b0110,
    Output_OD_50MHz    = 0b0111,
    Input_PullUpDown   = 0b1000,
    Alternate_PP_10MHz = 0b1001,
    Alternate_PP_2MHz  = 0b1010,
    Alternate_PP_50MHz = 0b1011,
    Alternate_OD_10MHz = 0b1101,
    Alternate_OD_2MHz  = 0b1110,
    Alternate_OD_50MHz = 0b1111
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

    void SetMode(Pin_t Pin, GPIO_Mode Mode);

    void SetPin(Pin_t Pin);

    void ClearPin(Pin_t Pin);

    void TogglePin(Pin_t Pin);

    PinState ReadPin(Pin_t Pin);

    void WritePin(Pin_t Pin, PinState State);
};
