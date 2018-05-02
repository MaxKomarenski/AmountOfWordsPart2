//
// Created by Victor on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_WORDSCOUNTER_H
#define AMOUNTOFWORDSPART2_WORDSCOUNTER_H

#include "MapsQueue.h"
#include <iostream>
#include "Queue.h"
#include <thread>
#include "ConditionVariables.h"

class WordsCounter {

private:

public:
    WordsCounter();

    WordsCounter(MapsQueue &mapsQueue, Queue &queue);


public:
    void count_words(MapsQueue &mapsQueue, Queue &queue);

};


#endif //AMOUNTOFWORDSPART2_WORDSCOUNTER_H
