//
// Created by Victor on 30.04.2018.
//

#include "WordsCounter.h"

 void WordsCounter::count_words(MapsQueue &mapsQueue, Queue &queue) {
    std::map <std::string, int> m;



        std::vector<std::string> data;
        while (true) {
            data = queue.pop();
            std::cout<<"Working "<<std::this_thread::get_id()<<"\n";
            for (int i = 0; i < data.size(); ++i){
                if (m.count(data.at(i))){
                    m[data.at(i)] += 1;
                }else{
                     m[data.at(i)] = 1;
                }

            }
            mapsQueue.push(m);
            if(conditions.readingIsFinished)
                break;
            m.clear();
        }
}

WordsCounter::WordsCounter(MapsQueue &mapsQueue, Queue &queue) {
   // tr = new std::thread(count_words, this, std::ref(mapsQueue), std::ref(queue));
}

void WordsCounter::join() {
  //  tr->join();
}

WordsCounter::WordsCounter() {}



