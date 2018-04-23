//
// Created by MaxKomarenski on 23.04.2018.
//

#include "Queue.h"

void Queue::push(std::vector<std::string> &v) {
    queue.push_back(v);
}

std::vector<std::string> Queue::pop() {
    if(!queue.empty()){
        std::vector<std::string> first = queue[0];
        queue.erase(queue.begin());
        return first;
    }
    std::vector<std::string> v;
    return v;
}

unsigned long Queue::getSize() {
    return queue.size();
}

bool Queue::isEmpty() {
    return queue.empty();
}


