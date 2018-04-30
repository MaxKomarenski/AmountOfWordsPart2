//
// Created by User on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_MAPSQUEUE_H
#define AMOUNTOFWORDSPART2_MAPSQUEUE_H


#include <map>
#include <vector>

class MapsQueue {
    std::vector<std::map<std::string, int>> queue;
public:
    void push(std::map<std::string, int> &m);
    std::map<std::string, int> pop();
    unsigned long getSize();
    bool isEmpty();

};


#endif //AMOUNTOFWORDSPART2_MAPSQUEUE_H