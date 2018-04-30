//
// Created by Victor on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_WORDSCOUNTER_H
#define AMOUNTOFWORDSPART2_WORDSCOUNTER_H

#include "MapsQueue.h"
#include <iostream>
#include "Queue.h"
#include <thread>

class WordsCounter {

private:
    std::thread tr;

public:
    WordsCounter(MapsQueue &mapsQueue, Queue &queue);


public:
    void count_words(MapsQueue &mapsQueue, Queue &queue);
    void join();

};


#endif //AMOUNTOFWORDSPART2_WORDSCOUNTER_H
