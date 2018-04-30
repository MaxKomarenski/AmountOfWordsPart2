//
// Created by User on 30.04.2018.
//

#include "MapsQueue.h"

void MapsQueue::push(std::map<std::string, int> &m) {
    std::lock_guard<std::mutex> lock(*gueue_mutex);
    queue->push_back(m);
}

std::map<std::string, int> MapsQueue::pop() {
    std::lock_guard<std::mutex> lock(*gueue_mutex);
    if(!queue->empty()){
        std::map<std::string, int> first = queue->at(0);
        queue->erase(queue->begin());
        return first;
    }
    std::map<std::string, int> m;
    return m;
}

unsigned long MapsQueue::getSize() {
    std::lock_guard<std::mutex> lock(*gueue_mutex);
    return queue->size();
}

bool MapsQueue::isEmpty() {
    std::lock_guard<std::mutex> lock(*gueue_mutex);
    return queue->empty();
}

MapsQueue::MapsQueue() {
     queue = new std::vector<std::map<std::string, int>>;
     gueue_mutex = new std::mutex();
}

MapsQueue::MapsQueue(MapsQueue &q) {
    queue = q.queue;
}
