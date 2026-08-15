#include "../../Platform/STM32F103/RCC_MemoryMap.hpp"
#include "../../Platform/STM32F103/GPIO_MemoryMap.hpp"
#include "GPIO.hpp"

GPIO::GPIO() : GPIOport{0, 0}
{
}

void GPIO::Init(Port_t port)
{
    switch (port)
    {
    case Port_t::GPIOA:

        GPIOport =
        {
            RCCReg::APB2ENR,
            RCCReg::APB2ENR_Bits::IOPAEN,

            GPIOReg::GPIOA::CRL,
            GPIOReg::GPIOA::CRH,
            GPIOReg::GPIOA::IDR,
            GPIOReg::GPIOA::ODR,
            GPIOReg::GPIOA::BSRR,
            GPIOReg::GPIOA::BRR
        };

        break;

    case Port_t::GPIOB:

        GPIOport =
        {
            RCCReg::APB2ENR,
            RCCReg::APB2ENR_Bits::IOPBEN,

            GPIOReg::GPIOB::CRL,
            GPIOReg::GPIOB::CRH,
            GPIOReg::GPIOB::IDR,
            GPIOReg::GPIOB::ODR,
            GPIOReg::GPIOB::BSRR,
            GPIOReg::GPIOB::BRR
        };

        break;

    case Port_t::GPIOC:

        GPIOport =
        {
            RCCReg::APB2ENR,
            RCCReg::APB2ENR_Bits::IOPCEN,

            GPIOReg::GPIOC::CRL,
            GPIOReg::GPIOC::CRH,
            GPIOReg::GPIOC::IDR,
            GPIOReg::GPIOC::ODR,
            GPIOReg::GPIOC::BSRR,
            GPIOReg::GPIOC::BRR
        };

        break;
    }
}

uintptr_t GPIO::GetReg() const
{
    return GPIOport.RCC_reg;
}

int GPIO::GetBit() const
{
    return GPIOport.RCC_reg;
}

void GPIO::SetMode(Pin_t Pin, GPIO_Mode Mode)
{
    uint32_t PinNumber = static_cast<uint32_t>(Pin);
    uint32_t Shift = (PinNumber % 8U) * 4U;

    uint32_t Mask = 0x0FU << Shift;
    uint32_t Value = static_cast<uint32_t>(Mode) << Shift;

    if (PinNumber < 8U)
    {
        Register32 GPIO_Register(GPIOport.CRL);
        GPIO_Register.modify(Mask, Value);
    }
    else
    {
        Register32 GPIO_Register(GPIOport.CRH);
        GPIO_Register.modify(Mask, Value);
    }
}

void GPIO::SetPin(Pin_t Pin)
{
    Register32 GPIO_Register(GPIOport.BSRR);
    GPIO_Register.set(static_cast<uint32_t>(Pin));
}

void GPIO::ClearPin(Pin_t Pin)
{
    Register32 GPIO_Register(GPIOport.BRR);
    GPIO_Register.set(static_cast<uint32_t>(Pin));
}

void GPIO::TogglePin(Pin_t Pin)
{
    Register32 GPIO_Register(GPIOport.ODR);

    if (GPIO_Register.read(static_cast<uint32_t>(Pin)))
    {
        Register32 GPIO_Clear(GPIOport.BRR);
        GPIO_Clear.set(static_cast<uint32_t>(Pin));
    }
    else
    {
        Register32 GPIO_Set(GPIOport.BSRR);
        GPIO_Set.set(static_cast<uint32_t>(Pin));
    }
}

PinState GPIO::ReadPin(Pin_t Pin)
{
    Register32 GPIO_Register(GPIOport.IDR);

    return GPIO_Register.read(static_cast<uint32_t>(Pin)) ? PinState::High : PinState::Low;
}