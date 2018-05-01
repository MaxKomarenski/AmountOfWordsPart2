//
// Created by Victor on 30.04.2018.
//

#include "ThreadDispatcher.h"




Queue &ThreadDispatcher::getQueue(){
    return queue;
}

ThreadDispatcher::ThreadDispatcher(Queue &queue, MapsQueue &mapsQueue) : queue(queue), mapsQueue(mapsQueue) {}

void ThreadDispatcher::test() {

    for (int i = 0; i < 5; i++) {
        word_counters.emplace_back(std::thread(count_words, this));
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
        mapsQueue.push(m);
        m.clear();
    }
}



