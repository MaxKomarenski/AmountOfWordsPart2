//
// Created by Victor on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_THREADDISPATCHER_H
#define AMOUNTOFWORDSPART2_THREADDISPATCHER_H

#include "ConditionVariables.h"
#include <vector>
#include <thread>
#include "WordsCounter.h"

class ThreadDispatcher {


private:
    Queue &queue;
    MapsQueue &mapsQueue;

    unsigned int concurentThreadsSupported = std::thread::hardware_concurrency();
    std::vector<std::thread> word_counters;
    //std::vector<WordsCounter> testvec;
    std::vector<std::thread> map_mergers;
public:

    ThreadDispatcher(Queue &queue, MapsQueue &mapsQueue);

    void test();


    Queue &getQueue();

};


#endif //AMOUNTOFWORDSPART2_THREADDISPATCHER_H
