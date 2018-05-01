//
// Created by User on 30.04.2018.
//

#include "MapReducer.h"

void MapReducer::map_reduce(MapsQueue &mapsQueue, Queue &queue){

    std::map<std::string, int> result;
    std::map<std::string, int> map1;
    std::map<std::string, int> map2;
    while (true) {
        {
            std::unique_lock<std::mutex> lck(conditions.data_mutex);
            if (conditions.readingIsFinished && queue.isEmpty()
                && mapsQueue.getSize() == 1 && !conditions.merging_in_process) {
                break;
            }

            conditions.queueHasMap.wait(lck, [&mapsQueue] { return mapsQueue.getSize() >= 2; });
            conditions.merging_in_process = true;

             map1 = mapsQueue.pop();
             map2 = mapsQueue.pop();
        }

            for (auto const &element : map2) {
                if (result.count(element.first)) {
                    result[element.first] += element.second;
                } else {
                    result[element.first] = element.second;
                }
            }

            for (auto const &element : map1) {
                if (result.count(element.first)) {
                    result[element.first] += element.second;
                } else {
                    result[element.first] = element.second;
                }

            }


            mapsQueue.push(result);
            std :: unique_lock<std::mutex> lck(conditions.data_mutex);
            conditions.merging_in_process = false;
            conditions.queueHasMap.notify_one();
            result.clear();
        }

}