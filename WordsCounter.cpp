//
// Created by Victor on 30.04.2018.
//

#include "WordsCounter.h"

 void WordsCounter::count_words(MapsQueue &mapsQueue, Queue &queue) {
     std::map <std::string, int> m;

     std::vector<std::string> data;
     while (true) {
         {
             std :: unique_lock<std::mutex> lck(conditions.read_mutex);
             if(conditions.readingIsFinished && queue.getSize() == 0) {
                 conditions.queueHasMap.notify_one();
                 conditions.word_counters_alive--;
                 break;
             }
             conditions.isData.wait(lck,[&queue] { return !conditions.readingIsFinished || queue.getSize() != 0;});
             data = queue.pop();
         }
         for (int i = 0; i < data.size(); ++i){
             if (m.count(data.at(i))){
                 m[data.at(i)] += 1;
             }else{
                 m[data.at(i)] = 1;
             }
         }
         {

             std :: unique_lock<std::mutex> lck(conditions.data_mutex);
             if(!m.empty())
                 mapsQueue.push(m);
             if(conditions.readingIsFinished && queue.getSize() == 0) {
                 conditions.queueHasMap.notify_one();
                 conditions.word_counters_alive--;
                 break;
             }
             conditions.queueHasMap.notify_one();
             m.clear();
         }
     }
}

WordsCounter::WordsCounter(MapsQueue &mapsQueue, Queue &queue) {

}


WordsCounter::WordsCounter() {}



