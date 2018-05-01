#include <iostream>
#include "FileReader.h"
#include "MapsQueue.h"
#include "ThreadDispatcher.h"


int main() {


    Queue queue;
    FileReader  fileReader(10000);
    MapsQueue mapsQueue;
  //  std::thread read(read_from_file,std::ref(queue));
   // read.join();
    ThreadDispatcher dispatcher(queue,mapsQueue);
    fileReader.start(queue);
    std::cout<<"start test\n";
    conditions.isData.notify_one();
    dispatcher.test();

    std::cout<<queue.getSize()<<"\n";






    std::cout<<queue.getSize()<<"\n";
    std::cout<<mapsQueue.getSize()<<"\n";



    return 0;
}


