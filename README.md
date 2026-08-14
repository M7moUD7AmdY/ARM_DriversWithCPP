# STM32 C++ Drivers

A collection of STM32 peripheral drivers implemented in C++.

The goal is to provide a simple, reusable, and clean C++ interface for STM32 peripherals while using STM32 HAL/LL internally.

---

## Project Structure

```text
STM32-CPP-Drivers/
│
├── MCAL/
│   ├── GPIO/
│   ├── UART/
│   ├── I2C/
│   ├── SPI/
│   ├── ADC/
│   ├── PWM/
│   ├── CAN/
│   ├── Timer/
│   ├── EXTI/
│   ├── DMA/
│   ├── RTC/
│   ├── Watchdog/
│   └── Flash/
│   └── RCC/
│
├── Services/
│   ├── Types
│   ├── Status
│   └── Utils
│
├── Examples/
│   ├── GPIO/
│   ├── UART/
│   ├── I2C/
│   └── SPI/
│
├── Tests/
│
├── README.md
└── CMakeLists.txt
```

---

## Available Drivers

### GPIO

General-purpose input/output.

```text
GPIO
├── Input
├── Output
├── Pull-up
├── Pull-down
├── Read
├── Write
└── Toggle
```

---

### UART

Universal asynchronous receiver/transmitter.

```text
UART
├── Transmit
├── Receive
├── Blocking
├── Interrupt
└── DMA
```

---

### I2C

Inter-integrated circuit communication.

```text
I2C
├── Master Transmit
├── Master Receive
├── Register Read
├── Register Write
├── Blocking
├── Interrupt
└── DMA
```

---

### SPI

Serial peripheral interface.

```text
SPI
├── Transmit
├── Receive
├── Transmit/Receive
├── Blocking
├── Interrupt
└── DMA
```

---

### ADC

Analog-to-digital converter.

```text
ADC
├── Single Channel
├── Multiple Channels
├── Polling
├── Interrupt
└── DMA
```

---

### PWM

Pulse-width modulation.

```text
PWM
├── Start
├── Stop
├── Duty Cycle
└── Frequency
```

---

### CAN

Controller Area Network.

```text
CAN
├── Transmit
├── Receive
├── Filters
├── Interrupt
└── FIFO
```

---

### Timer

STM32 timer peripheral.

```text
Timer
├── Basic Timer
├── Input Capture
├── Output Compare
├── PWM
└── Periodic Interrupt
```

---

### EXTI

External interrupt controller.

```text
EXTI
├── Rising Edge
├── Falling Edge
└── Rising/Falling Edge
```

---

### DMA

Direct memory access.

```text
DMA
├── Memory → Peripheral
├── Peripheral → Memory
└── Memory → Memory
```

---

### RTC

Real-time clock.

```text
RTC
├── Date
├── Time
├── Alarm
└── Calendar
```

---

### Watchdog

System watchdog peripherals.

```text
Watchdog
├── Independent Watchdog
└── Window Watchdog
```

---

### Flash

Internal STM32 Flash memory access.

```text
Flash
├── Read
├── Write
└── Erase
```

---

## Driver Structure

Each driver follows the same basic structure:

```text
Drivers/
└── GPIO/
    ├── Gpio.hpp
    └── Gpio.cpp
```

Example:

```text
Drivers/
└── UART/
    ├── Uart.hpp
    └── Uart.cpp
```

The C++ driver provides the interface, while STM32 HAL/LL is used internally.

```text
Application
     │
     ▼
C++ Driver
     │
     ▼
STM32 HAL / LL
     │
     ▼
STM32 Hardware
```

---

## Naming

Classes:

```cpp
Gpio
Uart
I2c
Spi
Adc
Pwm
Can
Timer
Exti
Dma
Rtc
Watchdog
Flash
```

Files:

```text
Gpio.hpp
Gpio.cpp

Uart.hpp
Uart.cpp

I2c.hpp
I2c.cpp
```

---

## Goal

Build a complete set of reusable STM32 peripheral drivers using C++ with a consistent API and structure.
