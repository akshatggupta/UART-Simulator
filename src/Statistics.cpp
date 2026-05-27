#include "Statistics.h"

#include <iostream>

int Statistics::framesSent = 0;
int Statistics::framesReceived = 0;
int Statistics::corruptedFrames = 0;
int Statistics::droppedFrames = 0;

void Statistics::printStats() {

    std::cout << "\n========== UART STATISTICS =========="
              << std::endl;

    std::cout << "Frames Sent      : "
              << framesSent
              << std::endl;

    std::cout << "Frames Received  : "
              << framesReceived
              << std::endl;

    std::cout << "Corrupted Frames : "
              << corruptedFrames
              << std::endl;

    std::cout << "Dropped Frames   : "
              << droppedFrames
              << std::endl;
}