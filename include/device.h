# include/Device.h

```cpp
#ifndef DEVICE_H
#define DEVICE_H

#include "UART.h"
#include <string>

class Device {
private:
    std::string name;
    UART uart;

public:
    Device(std::string name, int baudRate, Channel* channel);

    void sendMessage(const std::string& message);
    void receiveMessage(int messageLength);
};

#endif