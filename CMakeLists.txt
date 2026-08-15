cmake_minimum_required(VERSION 3.20)

project(ARM_M3_Cpp LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MCU cortex-m3)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mcpu=${MCU} -mthumb")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mcpu=${MCU} -mthumb")

set(COMMON_FLAGS
    -ffunction-sections
    -fdata-sections
    -fno-common
)

add_compile_options(${COMMON_FLAGS})

add_compile_definitions(
    STM32F103xC
)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/HAL
    ${CMAKE_SOURCE_DIR}/MCAL
    ${CMAKE_SOURCE_DIR}/MCAL/GPIO
    ${CMAKE_SOURCE_DIR}/MCAL/RCC
    ${CMAKE_SOURCE_DIR}/Platform/STM32F103
    ${CMAKE_SOURCE_DIR}/Services
)

set(SOURCES
    main.cpp

    MCAL/GPIO/GPIO.cpp
    MCAL/RCC/RCC.cpp

    startup/startup_stm32f103rc.s
    Services/syscalls.cpp
)

add_executable(${PROJECT_NAME}.elf ${SOURCES})

set(LINKER_SCRIPT
    ${CMAKE_SOURCE_DIR}/linker/STM32F103RCT6_FLASH.ld
)

target_link_options(${PROJECT_NAME}.elf PRIVATE
    -mcpu=${MCU}
    -mthumb
    -T${LINKER_SCRIPT}
    -Wl,--gc-sections
    -Wl,-Map=${PROJECT_NAME}.map
    -nostartfiles
)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex
            $<TARGET_FILE:${PROJECT_NAME}.elf>
            ${HEX_FILE}

    COMMAND ${CMAKE_OBJCOPY} -O binary
            $<TARGET_FILE:${PROJECT_NAME}.elf>
            ${BIN_FILE}

    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}.elf>
)