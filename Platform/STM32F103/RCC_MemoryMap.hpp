#pragma once

#include <cstdint>

namespace RCCReg
{
    constexpr uintptr_t BASE = 0x40021000UL;

    // ============================================================
    // RCC Register Addresses
    // ============================================================

    constexpr uintptr_t CR       = BASE + 0x00UL;
    constexpr uintptr_t CFGR     = BASE + 0x04UL;
    constexpr uintptr_t CIR      = BASE + 0x08UL;
    constexpr uintptr_t APB2RSTR = BASE + 0x0CUL;
    constexpr uintptr_t APB1RSTR = BASE + 0x10UL;
    constexpr uintptr_t AHBENR   = BASE + 0x14UL;
    constexpr uintptr_t APB2ENR  = BASE + 0x18UL;
    constexpr uintptr_t APB1ENR  = BASE + 0x1CUL;
    constexpr uintptr_t BDCR     = BASE + 0x20UL;
    constexpr uintptr_t CSR      = BASE + 0x24UL;


    // ============================================================
    // RCC_CR Bits
    // ============================================================

    namespace CR_Bits
    {
        constexpr uint32_t HSION   = (1UL << 0);
        constexpr uint32_t HSIRDY  = (1UL << 1);

        constexpr uint32_t HSITRIM = (0x1FUL << 3);
        constexpr uint32_t HSICAL  = (0xFFUL << 8);

        constexpr uint32_t HSEON   = (1UL << 16);
        constexpr uint32_t HSERDY  = (1UL << 17);
        constexpr uint32_t HSEBYP  = (1UL << 18);
        constexpr uint32_t CSSON   = (1UL << 19);

        constexpr uint32_t PLLON   = (1UL << 24);
        constexpr uint32_t PLLRDY  = (1UL << 25);
    }


    // ============================================================
    // RCC_CFGR Bits
    // ============================================================

    namespace CFGR_Bits
    {
        // System clock switch
        constexpr uint32_t SW      = (0x3UL << 0);

        constexpr uint32_t SW_HSI  = (0x0UL << 0);
        constexpr uint32_t SW_HSE  = (0x1UL << 0);
        constexpr uint32_t SW_PLL  = (0x2UL << 0);

        // System clock switch status
        constexpr uint32_t SWS     = (0x3UL << 2);

        constexpr uint32_t SWS_HSI = (0x0UL << 2);
        constexpr uint32_t SWS_HSE = (0x1UL << 2);
        constexpr uint32_t SWS_PLL = (0x2UL << 2);

        // AHB prescaler
        constexpr uint32_t HPRE    = (0xFUL << 4);

        // APB1 prescaler
        constexpr uint32_t PPRE1   = (0x7UL << 8);

        // APB2 prescaler
        constexpr uint32_t PPRE2   = (0x7UL << 11);

        // ADC prescaler
        constexpr uint32_t ADCPRE  = (0x3UL << 14);

        constexpr uint32_t ADCPRE_DIV2 = (0x0UL << 14);
        constexpr uint32_t ADCPRE_DIV4 = (0x1UL << 14);
        constexpr uint32_t ADCPRE_DIV6 = (0x2UL << 14);
        constexpr uint32_t ADCPRE_DIV8 = (0x3UL << 14);

        // PLL source
        constexpr uint32_t PLLSRC  = (1UL << 16);

        constexpr uint32_t PLLSRC_HSI_DIV2 = (0UL << 16);
        constexpr uint32_t PLLSRC_HSE     = (1UL << 16);

        // HSE divider before PLL
        constexpr uint32_t PLLXTPRE = (1UL << 17);

        constexpr uint32_t PLLXTPRE_HSE      = (0UL << 17);
        constexpr uint32_t PLLXTPRE_HSE_DIV2 = (1UL << 17);

        // PLL multiplication factor
        constexpr uint32_t PLLMUL = (0xFUL << 18);

        // USB prescaler
        constexpr uint32_t USBPRE = (1UL << 22);

        constexpr uint32_t USBPRE_DIV1_5 = (0UL << 22);
        constexpr uint32_t USBPRE_DIV1   = (1UL << 22);

        // Microcontroller clock output
        constexpr uint32_t MCO = (0x7UL << 24);

        constexpr uint32_t MCO_NO_CLOCK = (0x0UL << 24);
        constexpr uint32_t MCO_SYSCLK   = (0x4UL << 24);
        constexpr uint32_t MCO_HSI      = (0x5UL << 24);
        constexpr uint32_t MCO_HSE      = (0x6UL << 24);
        constexpr uint32_t MCO_PLL      = (0x7UL << 24);
    }


    // ============================================================
    // RCC_CIR Bits
    // ============================================================

    namespace CIR_Bits
    {
        // Interrupt flags
        constexpr uint32_t LSIRDYF  = (1UL << 0);
        constexpr uint32_t LSERDYF  = (1UL << 1);
        constexpr uint32_t HSIRDYF  = (1UL << 2);
        constexpr uint32_t HSERDYF  = (1UL << 3);
        constexpr uint32_t PLLRDYF  = (1UL << 4);
        constexpr uint32_t CSSF     = (1UL << 7);

        // Interrupt enables
        constexpr uint32_t LSIRDYIE = (1UL << 8);
        constexpr uint32_t LSERDYIE = (1UL << 9);
        constexpr uint32_t HSIRDYIE = (1UL << 10);
        constexpr uint32_t HSERDYIE = (1UL << 11);
        constexpr uint32_t PLLRDYIE = (1UL << 12);

        // Interrupt clears
        constexpr uint32_t LSIRDYC  = (1UL << 13);
        constexpr uint32_t LSERDYC  = (1UL << 14);
        constexpr uint32_t HSIRDYC  = (1UL << 15);
        constexpr uint32_t HSERDYC  = (1UL << 16);
        constexpr uint32_t PLLRDYC  = (1UL << 17);
        constexpr uint32_t CSSC     = (1UL << 23);
    }


    // ============================================================
    // RCC_APB2RSTR Bits
    // ============================================================

    namespace APB2RSTR_Bits
    {
        constexpr uint32_t AFIORST   = (1UL << 0);
        constexpr uint32_t IOPARST   = (1UL << 2);
        constexpr uint32_t IOPBRST   = (1UL << 3);
        constexpr uint32_t IOPCRST   = (1UL << 4);
        constexpr uint32_t IOPDRST   = (1UL << 5);
        constexpr uint32_t IOPERST   = (1UL << 6);
        constexpr uint32_t IOPFRST   = (1UL << 7);
        constexpr uint32_t IOPGRST   = (1UL << 8);
        constexpr uint32_t ADC1RST   = (1UL << 9);
        constexpr uint32_t ADC2RST   = (1UL << 10);
        constexpr uint32_t TIM1RST   = (1UL << 11);
        constexpr uint32_t SPI1RST   = (1UL << 12);
        constexpr uint32_t TIM8RST   = (1UL << 13);
        constexpr uint32_t USART1RST = (1UL << 14);
        constexpr uint32_t ADC3RST   = (1UL << 15);
    }


    // ============================================================
    // RCC_APB1RSTR Bits
    // ============================================================

    namespace APB1RSTR_Bits
    {
        constexpr uint32_t TIM2RST   = (1UL << 0);
        constexpr uint32_t TIM3RST   = (1UL << 1);
        constexpr uint32_t TIM4RST   = (1UL << 2);
        constexpr uint32_t TIM5RST   = (1UL << 3);
        constexpr uint32_t TIM6RST   = (1UL << 4);
        constexpr uint32_t TIM7RST   = (1UL << 5);
        constexpr uint32_t TIM12RST  = (1UL << 6);
        constexpr uint32_t TIM13RST  = (1UL << 7);
        constexpr uint32_t TIM14RST  = (1UL << 8);
        constexpr uint32_t WWDGRST   = (1UL << 11);
        constexpr uint32_t SPI2RST   = (1UL << 14);
        constexpr uint32_t SPI3RST   = (1UL << 15);
        constexpr uint32_t USART2RST = (1UL << 17);
        constexpr uint32_t USART3RST = (1UL << 18);
        constexpr uint32_t UART4RST  = (1UL << 19);
        constexpr uint32_t UART5RST  = (1UL << 20);
        constexpr uint32_t I2C1RST   = (1UL << 21);
        constexpr uint32_t I2C2RST   = (1UL << 22);
        constexpr uint32_t USBRST    = (1UL << 23);
        constexpr uint32_t CANRST    = (1UL << 25);
        constexpr uint32_t BKPRST    = (1UL << 27);
        constexpr uint32_t PWRRST    = (1UL << 28);
        constexpr uint32_t DACRST    = (1UL << 29);
    }


    // ============================================================
    // RCC_AHBENR Bits
    // ============================================================

    namespace AHBENR_Bits
    {
        constexpr uint32_t DMA1EN  = (1UL << 0);
        constexpr uint32_t DMA2EN  = (1UL << 1);
        constexpr uint32_t SRAMEN  = (1UL << 2);
        constexpr uint32_t FLITFEN = (1UL << 4);
        constexpr uint32_t CRCEN   = (1UL << 6);
        constexpr uint32_t FSMCEN  = (1UL << 8);
        constexpr uint32_t SDIOEN  = (1UL << 10);
    }


    // ============================================================
    // RCC_APB2ENR Bits
    // ============================================================

    namespace APB2ENR_Bits
    {
        constexpr uint32_t AFIOEN   = (1UL << 0);
        constexpr uint32_t IOPAEN   = (1UL << 2);
        constexpr uint32_t IOPBEN   = (1UL << 3);
        constexpr uint32_t IOPCEN   = (1UL << 4);
        constexpr uint32_t IOPDEN   = (1UL << 5);
        constexpr uint32_t IOPEEN   = (1UL << 6);
        constexpr uint32_t IOPFEN   = (1UL << 7);
        constexpr uint32_t IOPGEN   = (1UL << 8);
        constexpr uint32_t ADC1EN   = (1UL << 9);
        constexpr uint32_t ADC2EN   = (1UL << 10);
        constexpr uint32_t TIM1EN   = (1UL << 11);
        constexpr uint32_t SPI1EN   = (1UL << 12);
        constexpr uint32_t TIM8EN   = (1UL << 13);
        constexpr uint32_t USART1EN = (1UL << 14);
        constexpr uint32_t ADC3EN   = (1UL << 15);
    }


    // ============================================================
    // RCC_APB1ENR Bits
    // ============================================================

    namespace APB1ENR_Bits
    {
        constexpr uint32_t TIM2EN   = (1UL << 0);
        constexpr uint32_t TIM3EN   = (1UL << 1);
        constexpr uint32_t TIM4EN   = (1UL << 2);
        constexpr uint32_t TIM5EN   = (1UL << 3);
        constexpr uint32_t TIM6EN   = (1UL << 4);
        constexpr uint32_t TIM7EN   = (1UL << 5);
        constexpr uint32_t TIM12EN  = (1UL << 6);
        constexpr uint32_t TIM13EN  = (1UL << 7);
        constexpr uint32_t TIM14EN  = (1UL << 8);
        constexpr uint32_t WWDGEN   = (1UL << 11);
        constexpr uint32_t SPI2EN   = (1UL << 14);
        constexpr uint32_t SPI3EN   = (1UL << 15);
        constexpr uint32_t USART2EN = (1UL << 17);
        constexpr uint32_t USART3EN = (1UL << 18);
        constexpr uint32_t UART4EN  = (1UL << 19);
        constexpr uint32_t UART5EN  = (1UL << 20);
        constexpr uint32_t I2C1EN   = (1UL << 21);
        constexpr uint32_t I2C2EN   = (1UL << 22);
        constexpr uint32_t USBEN    = (1UL << 23);
        constexpr uint32_t CANEN    = (1UL << 25);
        constexpr uint32_t BKPEN    = (1UL << 27);
        constexpr uint32_t PWREN    = (1UL << 28);
        constexpr uint32_t DACEN    = (1UL << 29);
    }


    // ============================================================
    // RCC_BDCR Bits
    // ============================================================

    namespace BDCR_Bits
    {
        constexpr uint32_t LSEON   = (1UL << 0);
        constexpr uint32_t LSERDY  = (1UL << 1);
        constexpr uint32_t LSEBYP  = (1UL << 2);
        constexpr uint32_t RTCSEL  = (0x3UL << 8);
        constexpr uint32_t RTCSEL_NONE = (0x0UL << 8);
        constexpr uint32_t RTCSEL_LSE  = (0x1UL << 8);
        constexpr uint32_t RTCSEL_LSI  = (0x2UL << 8);
        constexpr uint32_t RTCSEL_HSE  = (0x3UL << 8);
        constexpr uint32_t RTCEN   = (1UL << 15);
        constexpr uint32_t BDRST   = (1UL << 16);
    }


    // ============================================================
    // RCC_CSR Bits
    // ============================================================

    namespace CSR_Bits
    {
        constexpr uint32_t LSION    = (1UL << 0);
        constexpr uint32_t LSIRDY   = (1UL << 1);
        constexpr uint32_t RMVF     = (1UL << 24);
        constexpr uint32_t PINRSTF  = (1UL << 26);
        constexpr uint32_t PORRSTF  = (1UL << 27);
        constexpr uint32_t SFTRSTF  = (1UL << 28);
        constexpr uint32_t IWDGRSTF = (1UL << 29);
        constexpr uint32_t WWDGRSTF = (1UL << 30);
        constexpr uint32_t LPWRRSTF = (1UL << 31);
    }
}