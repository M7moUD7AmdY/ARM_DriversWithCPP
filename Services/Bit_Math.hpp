#ifndef BIT_MATH_HPP
#define BIT_MATH_HPP
#include<cstdint>


class Register32
{
private:
    volatile uint32_t* Address;

public:
    Register32(uintptr_t Address)
        : Address(reinterpret_cast<volatile uint32_t*>(Address))
    {
    }

    void set(uint32_t Bit)
    {
        *Address |= (1UL << Bit);
    }

    void clear(uint32_t Bit)
    {
        *Address &= ~(1UL << Bit);
    }

    bool read(uint32_t Bit) const
    {
        return (*Address & (1UL << Bit)) != 0U;
    }

    void write(uint32_t Value)
    {
        *Address = Value;
    }

    void modify(uint32_t Mask, uint32_t Value)
    {
        uint32_t RegValue = *Address;

        RegValue &= ~Mask;
        RegValue |= (Value & Mask);

        *Address = RegValue;
    }
};

#endif