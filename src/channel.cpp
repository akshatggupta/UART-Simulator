#include "Channel.h"

void Channel::sendBit(int bit) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        wire.push(bit);
    }

    cv.notify_one();
}

int Channel::receiveBit() {

    std::unique_lock<std::mutex> lock(mtx);

    cv.wait(lock, [this]() {
        return !wire.empty();
    });

    int bit = wire.front();
    wire.pop();

    return bit;
}