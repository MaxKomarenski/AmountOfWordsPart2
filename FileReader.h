//
// Created by Victor on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_FILEREADER_H
#define AMOUNTOFWORDSPART2_FILEREADER_H

#include "Queue.h"
#include "fstream"
#include "algorithm"
#include "ConditionVariables.h"
#include <iostream>
class FileReader {

private:

    int block_size;
public:
    std::thread *reading_thread;
    FileReader(int block_size);
    void  start(Queue &queue,std::string file);


private:
    void read_from_file(Queue &queue, std::string file);






};


#endif //AMOUNTOFWORDSPART2_FILEREADER_H
