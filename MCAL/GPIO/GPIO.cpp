#include "../../Platform/STM32F103/RCC_MemoryMap.hpp"

#include "GPIO.hpp"

GPIO::GPIO() : GPIOport{0, 0}
{
}

void GPIO::Init(Port_t port)
{
    switch (port)
    {
    case Port_t::GPIOA:
        GPIOport.reg = RCCReg::APB2ENR;
        GPIOport.bit = RCCReg::APB2ENR_Bits::IOPAEN;
        break;

    case Port_t::GPIOB:
        GPIOport.reg = RCCReg::APB2ENR;
        GPIOport.bit = RCCReg::APB2ENR_Bits::IOPBEN;
        break;

    case Port_t::GPIOC:
        GPIOport.reg = RCCReg::APB2ENR;
        GPIOport.bit = RCCReg::APB2ENR_Bits::IOPCEN;
        break;

    case Port_t::GPIOD:
        GPIOport.reg = RCCReg::APB2ENR;
        GPIOport.bit = RCCReg::APB2ENR_Bits::IOPDEN;
        break;

    case Port_t::GPIOE:
        GPIOport.reg = RCCReg::APB2ENR;
        GPIOport.bit = RCCReg::APB2ENR_Bits::IOPEEN;
        break;

    case Port_t::GPIOF:
        GPIOport.reg = RCCReg::APB2ENR;
        GPIOport.bit = RCCReg::APB2ENR_Bits::IOPFEN;
        break;

    case Port_t::GPIOG:
        GPIOport.reg = RCCReg::APB2ENR;
        GPIOport.bit = RCCReg::APB2ENR_Bits::IOPGEN;
        break;
    }
}

uintptr_t GPIO::GetReg() const
{
    return GPIOport.reg;
}

int GPIO::GetBit() const
{
    return GPIOport.bit;
}

void SetMode(uint8_t Pin, PinMode Mode)
{

}

void SetPin(uint8_t Pin)
{

}

void ClearPin(uint8_t Pin)
{

}

void TogglePin(uint8_t Pin)
{

}

PinState ReadPin(uint8_t Pin)
{

}

void WritePin(uint8_t Pin, PinState State)
{
    
}