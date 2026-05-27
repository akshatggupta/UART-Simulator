#ifndef UART_H
#define UART_H

#include "Channel.h"

class UART {

private:

    int baudRate;

    int bitDelay;

    Channel* channel;

public:

    UART(int baudRate, Channel* channel);

    void transmit(char data);

    char receive();
};

#endif