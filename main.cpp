#include <iostream>
#include "FileReader.h"
#include "MapsQueue.h"
#include "ThreadDispatcher.h"
#include "Configuration.h"
#include "FileWriter.h"

inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}

template<class D>
inline long long to_us(const D& d)
{
    return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
}


void configure(Configuration& conf);

int main() {

    Configuration conf;
    try{
        configure(conf);
    }catch(...){
        return 0;
    }

    std::cout<<conf;

    auto stage1_start_time = get_current_time_fenced(); //time point


    Queue queue;
    FileReader  fileReader(10000);
    MapsQueue mapsQueue;
    ThreadDispatcher dispatcher(queue,mapsQueue);
    fileReader.start(queue, conf.getFileRead());
    dispatcher.start();
    fileReader.reading_thread->join();
    dispatcher.joinAll();






    auto finish_time = get_current_time_fenced();
    auto total_time = finish_time - stage1_start_time;

    FileWriter fileWriter;
    auto target = mapsQueue.pop();

    fileWriter.sort_by_letters_and_write_into_file(target, conf.getFileWriteSortedByLetters());
    fileWriter.sort_by_amount_and_write_into_file(target, conf.getFileWriteSortedByAmount());

    std::cout << "\nTime: " << to_us(total_time) << std::endl;

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



