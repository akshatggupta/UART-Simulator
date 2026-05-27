#ifndef UARTFRAME_H
#define UARTFRAME_H

#include <vector>

class UARTFrame {

public:

    std::vector<int> bits;

    UARTFrame(char data);

    void printFrame() const;
};

#endif