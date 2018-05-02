//
// Created by User on 30.04.2018.
//

#include "MapsQueue.h"

void MapsQueue::push(std::map<std::string, int> &m) {
    std::lock_guard<std::mutex> lock(gueue_mutex);
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
    std::lock_guard<std::mutex> lock(gueue_mutex);
    return queue.size();
}

bool MapsQueue::isEmpty() {
    std::lock_guard<std::mutex> lock(gueue_mutex);
    return queue.empty();
}

MapsQueue::MapsQueue() {

}

MapsQueue::MapsQueue(MapsQueue &q) {
    queue = q.queue;
}

const std::vector<std::map<std::string, int>> &MapsQueue::getQueue() const {
    return queue;
}
