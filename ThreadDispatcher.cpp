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

void ThreadDispatcher::count_words() {
    std::map <std::string, int> m;

    std::vector<std::string> data;
    while (true) {
        {
            std :: unique_lock<std::mutex> lck(conditions.data_mutex);
            if(conditions.readingIsFinished && queue.isEmpty())
                break;
            conditions.isData.wait(lck,[this] { return !queue.isEmpty();});
            data = queue.pop();
        }
        for (int i = 0; i < data.size(); ++i){
            if (m.count(data.at(i))){
                m[data.at(i)] += 1;
            }else{
                m[data.at(i)] = 1;
            }

        }
        std :: unique_lock<std::mutex> lck(conditions.data_mutex);
        conditions.queueHasMap.notify_one();
        mapsQueue.push(m);
        m.clear();
    }
}



