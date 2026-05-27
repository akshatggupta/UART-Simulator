#include "device.h"
#include <iostream>

Device::Device(std::string name,
               int baudRate,
               Channel* channel)
    : name(name), uart(baudRate, channel) {}

void Device::sendMessage(const std::string& message) {

    std::cout << "\n========== "
              << name
              << " TRANSMITTING =========="
              << std::endl;

    for (char c : message) {
        uart.transmit(c);
    }
}

void Device::receiveMessage(int messageLength) {

    std::cout << "\n========== "
              << name
              << " RECEIVING =========="
              << std::endl;

    std::string received;

    for (int i = 0; i < messageLength; i++) {
        received += uart.receive();
    }

    std::cout << "\nFinal Message Received: "
              << received
              << std::endl;
}