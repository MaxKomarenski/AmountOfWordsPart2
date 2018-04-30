//
// Created by Victor on 30.04.2018.
//

#include "WordsCounter.h"

void WordsCounter::count_words(MapsQueue &mapsQueue, Queue &queue) {
    std::map <std::string, int> m;


    std::cout<<"THREAD "<<std::this_thread::get_id()<<"\n";
//    for (int i = 0; i < words.size(); ++i){
//        if (m.count(words.at(i))){
//            m[words.at(i)] += 1;
//        }else{
//            m[words.at(i)] = 1;
//        }
//        mapsQueue.push(m);
//    }
}

WordsCounter::WordsCounter(MapsQueue &mapsQueue, Queue &queue) {
    tr = std::thread(count_words, this, std::ref(mapsQueue), std::ref(queue));
}

void WordsCounter::join() {
    tr.join();
}



