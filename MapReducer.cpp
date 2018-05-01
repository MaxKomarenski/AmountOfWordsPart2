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
                conditions.reduce_finished.notify_one();
                break;
            }

            conditions.queueHasMap.wait(lck, [&mapsQueue] { return mapsQueue.getSize() >= 2; });
            conditions.merging_in_process = true;

             map1 = mapsQueue.pop();
             map2 = mapsQueue.pop();
        }
           // std::cout<<"Size of mapsQueue after popping"<<mapsQueue.getSize()<<"\n";
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


            std :: unique_lock<std::mutex> lck(conditions.data_mutex);
           // std::cout<<"Pushing merged map\n";
            mapsQueue.push(result);
            conditions.merging_in_process = false;
            conditions.queueHasMap.notify_one();
            result.clear();
        }

}