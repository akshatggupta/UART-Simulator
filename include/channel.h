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

    double corruptionProbability;
    double dropProbability;

public:
    Channel(double corruption = 0.05,
            double drop = 0.02);

    void sendBit(int bit);
    int receiveBit();

    int applyNoise(int bit);
};

#endif