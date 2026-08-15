#include "MCAL/RCC/RCC.hpp"
#include "MCAL/GPIO/GPIO.hpp"


int main()
{


    GPIO GPIOA;

    GPIOA.Init(GPIOA);
    GPIOA.SetMode(PIN0,Output_PP_10MHz);




    return 0;
}