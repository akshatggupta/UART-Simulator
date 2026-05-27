# include/Channel.h

```cpp
#ifndef CHANNEL_H
#define CHANNEL_H

#include <queue>
#include <mutex>
#include <condition_variable>

class Channel {
private:
    std::queue<int> wire;
    std::mutex mtx;
    std::condition_variable cv;

public:
    void sendBit(int bit);
    int receiveBit();
};

#endif
