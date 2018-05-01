//
// Created by Victor on 30.04.2018.
//

#include "ThreadDispatcher.h"




Queue &ThreadDispatcher::getQueue(){
    return queue;
}

ThreadDispatcher::ThreadDispatcher(Queue &queue, MapsQueue &mapsQueue) : queue(queue), mapsQueue(mapsQueue) {}

void ThreadDispatcher::test() {

    auto *wc_ptr = new WordsCounter(mapsQueue,queue);

    for (int i = 0; i < 5; i++) {
        word_counters.emplace_back(std::thread(&WordsCounter::count_words, wc_ptr, std::ref(mapsQueue), std::ref(queue)));
    }
    for (int i = 0; i < 5; i++) {
        word_counters[i].join();
    }

}





