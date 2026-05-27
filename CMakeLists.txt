cmake_minimum_required(VERSION 3.10)

project(UARTSimulator)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include header files
include_directories(include)

# Create executable
add_executable(uart_simulator

    src/main.cpp
    src/UART.cpp
    src/UARTFrame.cpp
    src/Channel.cpp
    src/Device.cpp
    src/Statistics.cpp
)