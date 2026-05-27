#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics {
public:
    static int framesSent;
    static int framesReceived;
    static int corruptedFrames;
    static int droppedFrames;

    static void printStats();
};

#endif