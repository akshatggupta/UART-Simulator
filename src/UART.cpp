#include "UART.h"
#include "UARTFrame.h"
#include "Statistics.h"

#include <iostream>
#include <thread>
#include <chrono>
#include <bitset>
#include <vector>

UART::UART(int baudRate, Channel* channel)
    : baudRate(baudRate), channel(channel) {

    bitDelay = 1000000 / baudRate;
}

void UART::transmit(char data) {

    // Statistics Update
    Statistics::framesSent++;

    UARTFrame frame(data);

    std::cout << "\n[TX] Sending Character: "
              << data
              << std::endl;

    std::cout << "[TX] Binary: "
              << std::bitset<8>(data)
              << std::endl;

    std::cout << "[TX] UART Frame: ";

    frame.printFrame();

    for (int bit : frame.bits) {

        std::cout << "[TX] Bit Sent: "
                  << bit
                  << std::endl;

        channel->sendBit(bit);

        std::this_thread::sleep_for(
            std::chrono::microseconds(bitDelay)
        );
    }
}

char UART::receive() {

    // Statistics Update
    Statistics::framesReceived++;

    std::vector<int> receivedBits;

    int startBit;

    do {
        startBit = channel->receiveBit();
    } while (startBit != 0);

    std::cout << "\n[RX] Start Bit Detected"
              << std::endl;

    for (int i = 0; i < 8; i++) {

        int bit = channel->receiveBit();

        receivedBits.push_back(bit);

        std::cout << "[RX] Bit Received: "
                  << bit
                  << std::endl;
    }

    int stopBit = channel->receiveBit();

    if (stopBit != 1) {

        std::cout << "[ERROR] Invalid Stop Bit"
                  << std::endl;
    }

    char reconstructed = 0;

    for (int i = 0; i < 8; i++) {
        reconstructed |= (receivedBits[i] << i);
    }

    std::cout << "[RX] Character Received: "
              << reconstructed
              << std::endl;

    return reconstructed;
}