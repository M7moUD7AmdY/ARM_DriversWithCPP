#include "GPIO.hpp"

GPIO::GPIO() : GPIOport{0, 0}
{
}

void GPIO::Init(Port_t port)
{
    switch (port)
    {
        case Port_t::GPIOA:
            GPIOport.reg = 11;
            GPIOport.bit = 0;
            break;

        case Port_t::GPIOB:
            GPIOport.reg = 11;
            GPIOport.bit = 1;
            break;
    }
}

int GPIO::GetReg() const
{
    return GPIOport.reg;
}

int GPIO::GetBit() const
{
    return GPIOport.bit;
}