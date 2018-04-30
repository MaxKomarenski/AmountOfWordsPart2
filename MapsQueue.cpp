//
// Created by User on 30.04.2018.
//

#include "MapsQueue.h"

void MapsQueue::push(std::map<std::string, int> &m) {
    queue.push_back(m);
}

std::map<std::string, int> MapsQueue::pop() {
    if(!queue.empty()){
        std::map<std::string, int> first = queue[0];
        queue.erase(queue.begin());
        return first;
    }
    std::map<std::string, int> m;
    return m;
}

unsigned long MapsQueue::getSize() {
    return queue.size();
}

bool MapsQueue::isEmpty() {
    return queue.empty();
}