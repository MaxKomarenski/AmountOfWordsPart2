#include <iostream>
#include "FileReader.h"
#include "MapsQueue.h"
#include "ThreadDispatcher.h"
#include "Configuration.h"


void configure(Configuration& conf);

int main() {

    Configuration conf;
//    try{
//        configure(conf);
//    }catch(...){
//        return 0;
//    }

   // std::cout<<conf;



    Queue queue;
    FileReader  fileReader(4);
    MapsQueue mapsQueue;
    ThreadDispatcher dispatcher(queue,mapsQueue);
    fileReader.start(queue);
    dispatcher.test();


    std::cout << "FIISH SIZE: " << mapsQueue.getSize() << "\n";
    for(auto elem : mapsQueue.getQueue()){
        for( auto m :elem){
            std::cout<<m.first<<" "<<m.second<<"\n";
        }
    }



    return 0;
}


void configure(Configuration& conf){

    std::ifstream configuration("config.txt");
    if(!configuration.is_open()){
        std::cout<<"No configuration file found\nfile name should be config.txt\nIt will be created for you\n"<<
                 "Fill config info and restart program";
        std::ofstream configFile;
        configFile.open("config.txt");
        configFile<<conf.getFileReadToken()<<"\n"<<conf.getFileWriteSortedByAmountToken()<<"\n"
                  <<conf.getFileWriteSortedByLettersToken()<<"\n";


        throw EIO;

    }


    char buf[50];
    std::string input_string;
    while (configuration.getline(buf, 50)) {
        input_string.clear();
        input_string.append(buf);
        if(input_string.find(conf.getFileReadToken())==0){

            conf.setFileRead(conf.parseString(input_string));

        } else if(input_string.find(conf.getFileWriteSortedByAmountToken())==0){


            conf.setFileWriteSortedByAmount(conf.parseString(input_string));

        } else if(input_string.find(conf.getFileWriteSortedByLettersToken())==0){

            conf.setFileWriteSortedByLetters(conf.parseString(input_string));

        }

    }
}



