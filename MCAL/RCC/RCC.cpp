
#include "RCC.hpp"
#include "../../Services/Bit_Math.hpp"

template<typename T>
void RCC<T>::RCC_InitSysClock()
{
}

template<typename T>
void RCC<T>::RCC_Enable_clock( T& peripheral)
{
    // Enable clock
    Register32<peripheral.GetReg()>::set(peripheral.GetBit());
}

template<typename T>
void RCC<T>::RCC_Disable_clock( T& peripheral)
{
    // Disable clock
    Register32<peripheral.GetReg()>::clear(peripheral.GetBit());

}



