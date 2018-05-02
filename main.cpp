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


int main() {

    Configuration conf;
    try{
        Configuration::configure(conf);
    }catch(...){
        return 0;
    }

    std::cout<<conf;

    auto stage1_start_time = get_current_time_fenced(); //time point

    Queue queue;
    FileReader  fileReader(50000);
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
    std::cout << "\nTime sec : " << to_us(total_time)/1000000 << std::endl;

    return 0;
}






