#include <iostream>
#include "FileReader.h"
#include "MapsQueue.h"
#include "ThreadDispatcher.h"


int main() {


    Queue queue;
    FileReader  fileReader(15);
    MapsQueue mapsQueue;
    ThreadDispatcher dispatcher(queue,mapsQueue);
    fileReader.start(queue);
    std::cout<<"start test\n";
    std::cout<<queue.getSize()<<"\n";
    dispatcher.test();

    std::cout<<queue.getSize()<<"\n";
    std::cout<<mapsQueue.getSize()<<"\n";



    return 0;
}


