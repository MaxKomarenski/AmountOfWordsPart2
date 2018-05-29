//
// Created by Victor on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_THREADDISPATCHER_H
#define AMOUNTOFWORDSPART2_THREADDISPATCHER_H

#include "ConditionVariables.h"
#include <vector>
#include <thread>
#include "WordsCounter.h"
#include "MapReducer.h"
class ThreadDispatcher {


private:
    Queue &queue;
    MapsQueue &mapsQueue;


    unsigned int concurentThreadsSupported = std::thread::hardware_concurrency();
    int max_word_counters;
    int max_map_redusers;
    std::vector<std::thread> word_counters;
    std::vector<std::thread> map_mergers;
public:

    ThreadDispatcher(Queue &queue, MapsQueue &mapsQueue);

    void start();

    void joinAll();

    Queue &getQueue();

};


#endif //AMOUNTOFWORDSPART2_THREADDISPATCHER_H
