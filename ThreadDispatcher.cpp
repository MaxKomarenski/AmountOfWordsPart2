//
// Created by Victor on 30.04.2018.
//

#include "ThreadDispatcher.h"






void ThreadDispatcher::count_words() {
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


Queue &ThreadDispatcher::getQueue(){
    return queue;
}

ThreadDispatcher::ThreadDispatcher(Queue &queue, MapsQueue &mapsQueue) : queue(queue), mapsQueue(mapsQueue) {}

void ThreadDispatcher::test() {

    conditions.isData;
    for(int i=0; i<10; i++){

        testvec.emplace_back(WordsCounter(mapsQueue, queue));
    }
    for(int i=0; i<10; i++){
        testvec[i].join();
    }

}



