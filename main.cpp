#include <iostream>
#include "FileReader.h"
#include "MapsQueue.h"
#include "ThreadDispatcher.h"


int main() {


    Queue queue;
    FileReader  fileReader(10000);
    MapsQueue mapsQueue;
    ThreadDispatcher dispatcher(queue,mapsQueue);
    fileReader.start(queue);
    std::cout<<"start test\n";
    std::cout<<queue.getSize()<<"\n";
    dispatcher.test();


    std::cout << "FIISH SIZE: " << mapsQueue.getSize() << "\n";
    for(auto elem : mapsQueue.getQueue()){
        for( auto m :elem){
            std::cout<<m.first<<" "<<m.second<<"\n";
        }
    }



    return 0;
}


