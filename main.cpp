#include <iostream>
#include "FileReader.h"
#include "MapsQueue.h"
#include "ThreadDispatcher.h"

int main() {


    Queue queue;
    FileReader  fileReader(10000);
    MapsQueue mapsQueue;
    fileReader.start(queue);
    std::cout<<queue.getSize()<<"\n";
    ThreadDispatcher dispatcher(queue,mapsQueue);

  //  dispatcher.setQueue(queue);
    //dispatcher.setMapsQueue(mapsQueue);
    dispatcher.getQueue().pop();

    std::cout<<queue.getSize()<<"\n";
    dispatcher.test();
   // ThreadDispatcher dispatcher(mapsQueue,queue);

//    for(int i=0; i<8; i++){
//        WordsCounter w;
//        w.start_thread(mapsQueue,queue);
//        dispatcher.getWord_counters().push_back(w);
//    }
//    for(auto wc:dispatcher.getWord_counters()){
//        wc.join();
//    }

//    std::vector<std::string> words;
//    while (!(words = queue.pop()).empty()){
//        for(auto s: words){
//            std::cout<<s<<"\n";
//        }
//        std::cout<<"BLOCK:  \n";
//    }

    return 0;
}
