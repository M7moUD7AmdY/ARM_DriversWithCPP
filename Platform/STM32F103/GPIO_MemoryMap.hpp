#pragma once

#include <cstdint>

namespace GPIOReg
{
    // ============================================================
    // GPIO Base Addresses
    // ============================================================

    constexpr uintptr_t GPIOA_BASE = 0x40010800UL;
    constexpr uintptr_t GPIOB_BASE = 0x40010C00UL;
    constexpr uintptr_t GPIOC_BASE = 0x40011000UL;
    constexpr uintptr_t GPIOD_BASE = 0x40011400UL;
    constexpr uintptr_t GPIOE_BASE = 0x40011800UL;
    constexpr uintptr_t GPIOF_BASE = 0x40011C00UL;
    constexpr uintptr_t GPIOG_BASE = 0x40012000UL;


    // ============================================================
    // GPIO Register Offsets
    // ============================================================

    constexpr uintptr_t CRL_OFFSET  = 0x00UL;
    constexpr uintptr_t CRH_OFFSET  = 0x04UL;
    constexpr uintptr_t IDR_OFFSET  = 0x08UL;
    constexpr uintptr_t ODR_OFFSET  = 0x0CUL;
    constexpr uintptr_t BSRR_OFFSET = 0x10UL;
    constexpr uintptr_t BRR_OFFSET  = 0x14UL;
    constexpr uintptr_t LCKR_OFFSET = 0x18UL;


    // ============================================================
    // GPIOA Registers
    // ============================================================

    namespace GPIOA
    {
        constexpr uintptr_t BASE = GPIOA_BASE;

        constexpr uintptr_t CRL  = BASE + CRL_OFFSET;
        constexpr uintptr_t CRH  = BASE + CRH_OFFSET;
        constexpr uintptr_t IDR  = BASE + IDR_OFFSET;
        constexpr uintptr_t ODR  = BASE + ODR_OFFSET;
        constexpr uintptr_t BSRR = BASE + BSRR_OFFSET;
        constexpr uintptr_t BRR  = BASE + BRR_OFFSET;
        constexpr uintptr_t LCKR = BASE + LCKR_OFFSET;
    }


    // ============================================================
    // GPIOB Registers
    // ============================================================

    namespace GPIOB
    {
        constexpr uintptr_t BASE = GPIOB_BASE;

        constexpr uintptr_t CRL  = BASE + CRL_OFFSET;
        constexpr uintptr_t CRH  = BASE + CRH_OFFSET;
        constexpr uintptr_t IDR  = BASE + IDR_OFFSET;
        constexpr uintptr_t ODR  = BASE + ODR_OFFSET;
        constexpr uintptr_t BSRR = BASE + BSRR_OFFSET;
        constexpr uintptr_t BRR  = BASE + BRR_OFFSET;
        constexpr uintptr_t LCKR = BASE + LCKR_OFFSET;
    }


    // ============================================================
    // GPIOC Registers
    // ============================================================

    namespace GPIOC
    {
        constexpr uintptr_t BASE = GPIOC_BASE;

        constexpr uintptr_t CRL  = BASE + CRL_OFFSET;
        constexpr uintptr_t CRH  = BASE + CRH_OFFSET;
        constexpr uintptr_t IDR  = BASE + IDR_OFFSET;
        constexpr uintptr_t ODR  = BASE + ODR_OFFSET;
        constexpr uintptr_t BSRR = BASE + BSRR_OFFSET;
        constexpr uintptr_t BRR  = BASE + BRR_OFFSET;
        constexpr uintptr_t LCKR = BASE + LCKR_OFFSET;
    }


}