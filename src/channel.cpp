#include "Channel.h"
#include "Statistics.h"

#include <random>

Channel::Channel(double corruption,
                 double drop)
    : corruptionProbability(corruption),
      dropProbability(drop) {}

int Channel::applyNoise(int bit) {

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<> dist(0.0, 1.0);

    double randomValue = dist(gen);

    if (randomValue < corruptionProbability) {

        Statistics::corruptedFrames++;

        return !bit;
    }

    return bit;

}
void Channel::sendBit(int bit) {

    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution<> dist(0.0, 1.0);

    double randomValue = dist(gen);

    if (randomValue < dropProbability) {

        Statistics::droppedFrames++;

        return;
    }

    bit = applyNoise(bit);

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