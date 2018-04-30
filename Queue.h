//
// Created by MaxKomarenski on 23.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_QUEUE_H
#define AMOUNTOFWORDSPART2_QUEUE_H

#include <string>
#include <vector>
#include <mutex>


class Queue {
    std::vector<std::vector<std::string>> queue;
    std::mutex gueue_mutex;
public:
    void push(std::vector<std::string> &v);
    std::vector<std::string> pop();
    unsigned long getSize();
    bool isEmpty();
};


#endif //AMOUNTOFWORDSPART2_QUEUE_H
