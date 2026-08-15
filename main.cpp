#include "MCAL/RCC/RCC.hpp"
#include "MCAL/GPIO/GPIO.hpp"

int main()
{
    // Initialize System Clock
    RCC<GPIO>::RCC_InitSysClock();

    // Create GPIOC object
    GPIO GPIOC;

    // Initialize GPIOC
    GPIOC.Init(Port_t::GPIOC);

    // Enable GPIOC clock
    RCC<GPIO>::RCC_Enable_clock(GPIOC);

    // Configure PC13 as Push-Pull Output, 2 MHz
    GPIOC.SetMode(Pin_t::PIN1, GPIO_Mode::Output_PP_2MHz);

    while (1)
    {
        // Blue Pill LED is Active-Low
        GPIOC.ClearPin(Pin_t::PIN1);

        for (volatile uint32_t i = 0; i < 1000000; ++i);

        GPIOC.SetPin(Pin_t::PIN1);

        for (volatile uint32_t i = 0; i < 1000000; ++i);
    }
}