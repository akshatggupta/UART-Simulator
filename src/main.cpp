#include "Device.h"
#include "Channel.h"
#include "Statistics.h"

#include <iostream>
#include <thread>

int main() {

    Channel serialChannel(0.10, 0.03);

    int baudRate = 9600;

    Device deviceA(
        "DEVICE A",
        baudRate,
        &serialChannel
    );

    Device deviceB(
        "DEVICE B",
        baudRate,
        &serialChannel
    );

    std::string message;

    std::cout << "===================================="
              << std::endl;

    std::cout << " UART COMMUNICATION SIMULATOR "
              << std::endl;

    std::cout << "===================================="
              << std::endl;

    std::cout << "\nEnter message: ";

    std::getline(std::cin, message);

    std::thread receiver([&]() {
        deviceB.receiveMessage(message.length());
    });

    std::thread transmitter([&]() {
        deviceA.sendMessage(message);
    });

    transmitter.join();
    receiver.join();

    Statistics::printStats();

    return 0;
}