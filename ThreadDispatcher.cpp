//
// Created by Victor on 30.04.2018.
//

#include "ThreadDispatcher.h"




Queue &ThreadDispatcher::getQueue(){
    return queue;
}

ThreadDispatcher::ThreadDispatcher(Queue &queue, MapsQueue &mapsQueue) : queue(queue), mapsQueue(mapsQueue) {

    max_word_counters = (concurentThreadsSupported/2)-1;
    max_map_redusers = max_word_counters + 1;

}

void ThreadDispatcher::start() {
    conditions.word_counters_alive = max_word_counters;
    for (int i = 0; i < max_map_redusers; i++) {
        map_mergers.emplace_back(std::thread(&MapReducer::map_reduce, mr_ptr, std::ref(mapsQueue), std::ref(queue)));
    }
    for (int i = 0; i < max_word_counters; i++) {
        word_counters.emplace_back(std::thread(&WordsCounter::count_words, wc_ptr, std::ref(mapsQueue), std::ref(queue)));
    }
}
void ThreadDispatcher::joinAll(){
    for (int i = 0; i < max_map_redusers; i++) {
        map_mergers[i].join();
    }
    for (int i = 0; i < max_word_counters; i++) {
        word_counters[i].join();
    }
}





