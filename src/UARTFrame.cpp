#include "UARTFrame.h"

#include <iostream>

UARTFrame::UARTFrame(char data) {

    // Start Bit
    bits.push_back(0);

    // Data Bits (LSB First)
    for (int i = 0; i < 8; i++) {
        bits.push_back((data >> i) & 1);
    }

    // Stop Bit
    bits.push_back(1);
}

void UARTFrame::printFrame() const {

    for (int bit : bits) {
        std::cout << bit;
    }

    std::cout << std::endl;
}