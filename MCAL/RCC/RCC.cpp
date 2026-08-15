#include "RCC.hpp"
#include "../GPIO/GPIO.hpp"

template<typename T>
void RCC<T>::RCC_InitSysClock()
{
}

template<typename T>
void RCC<T>::RCC_Enable_clock(T& peripheral)
{
    Register32 Register(peripheral.GetReg());
    Register.set(peripheral.GetBit());
}

template<typename T>
void RCC<T>::RCC_Disable_clock(T& peripheral)
{
    Register32 Register(peripheral.GetReg());
    Register.clear(peripheral.GetBit());
}

template class RCC<GPIO>;
