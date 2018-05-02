//
// Created by User on 30.04.2018.
//

#include "MapReducer.h"

void MapReducer::map_reduce(MapsQueue &mapsQueue, Queue &queue){

    std::map<std::string, int> result;
    std::map<std::string, int> map1;
    std::map<std::string, int> map2;

    while (true) {

        std :: unique_lock<std::mutex> lck(conditions.data_mutex);
        conditions.queueHasMap.wait(lck,[&queue, &mapsQueue] { return mapsQueue.getSize() >= 2 || !conditions.word_counters_alive;});
        if( conditions.word_counters_alive == 0 && mapsQueue.getSize() == 1){
            conditions.queueHasMap.notify_all();
            break;
        }
        map1 = mapsQueue.pop();
        map2 = mapsQueue.pop();
        lck.unlock();

        merge(map1, map2,result);
        mapsQueue.push(result);
        conditions.queueHasMap.notify_one();



        result.clear();
        lck.lock();
        if(conditions.word_counters_alive == 0 && mapsQueue.getSize() == 1){
            conditions.queueHasMap.notify_all();
            lck.unlock();
            break;
        }
        lck.unlock();

        }
}

std::map<std::string, int> & MapReducer::merge(std::map<std::string, int> m1, std::map<std::string, int> m2,std::map<std::string, int> &result) {



    for (auto const &element : m2) {
        if (result.count(element.first)) {
            result[element.first] += element.second;
        } else {
            result[element.first] = element.second;
        }
    }

    for (auto const &element : m1) {
        if (result.count(element.first)) {
            result[element.first] += element.second;
        } else {
            result[element.first] = element.second;
        }
    }


    return result;
}
