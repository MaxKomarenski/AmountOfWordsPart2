//
// Created by User on 30.04.2018.
//

#include "MapReducer.h"

void MapReducer::map_reduce(MapsQueue &mapsQueue, Queue &queue){

    while (true) {
        std::map<std::string, int> result;

        {
            std::unique_lock<std::mutex> lck(conditions.data_mutex);
            if (conditions.readingIsFinished && queue.isEmpty())
                break;
            conditions.isData.wait(lck, [&queue] { return queue.getSize() >= 2; });

            //merge in one
            std::map<std::string, int> map1 = mapsQueue.pop();
            std::map<std::string, int> map2 = mapsQueue.pop();

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

        }

            std :: unique_lock<std::mutex> lck(conditions.data_mutex);
            mapsQueue.push(result);
            conditions.queueHasMap.notify_one();
            result.clear();

        }

}