//
// Created by MaxKomarenski on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_MAPREDUCER_H
#define AMOUNTOFWORDSPART2_MAPREDUCER_H

#include <map>
#include <vector>
#include <string>
#include "MapsQueue.h"
#include "Queue.h"
#include <iostream>

class MapReducer {

public:
    void map_reduce(MapsQueue &mapsQueue, Queue &queue);
    std::map<std::string, int> & merge(std::map<std::string, int> m1, std::map<std::string, int> m2, std::map<std::string, int> &result);

};


#endif //AMOUNTOFWORDSPART2_MAPREDUCER_H
