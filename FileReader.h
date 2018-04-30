//
// Created by Victor on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_FILEREADER_H
#define AMOUNTOFWORDSPART2_FILEREADER_H

#include "Queue.h"
#include "fstream"
#include "algorithm"
class FileReader {

private:
    int block_size;
public:
    FileReader(int block_size);

public:
    void read_from_file(Queue &queue);






};


#endif //AMOUNTOFWORDSPART2_FILEREADER_H
