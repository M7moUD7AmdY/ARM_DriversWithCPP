#pragma onece
#include<cstdint>




template<uintptr_t Address>
class Register32
{
public:
    static uint32_t read()
    {
        return *reinterpret_cast<volatile uint32_t*>(Address);
    }
    static void write(uint32_t value)
    {   
        *reinterpret_cast<volatile uint32_t*>(Address)=value;
    }
    static void set(uint32_t bit)
    {
        *reinterpret_cast<volatile uint32_t*>(Address)|=(1<<bit);
    }
    static void clear(uint32_t bit)
    {
        *reinterpret_cast<volatile uint32_t*>(Address) &=(1<<bit);

    }
    static void toggle(uint32_t bit)
    {
        *reinterpret_cast<volatile uint32_t*>(Address) ^=(1<<bit);

    }
};