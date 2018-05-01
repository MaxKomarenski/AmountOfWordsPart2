//
// Created by Victor on 01.05.2018.
//

#ifndef AMOUNTOFWORDSPART2_FILEWRITER_H
#define AMOUNTOFWORDSPART2_FILEWRITER_H


#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

class FileWriter {
public:

    void sort_by_letters_and_write_into_file(std::map<std::string, int> m, std::string filename);
    void sort_by_amount_and_write_into_file(std::map<std::string, int> m, std::string filename);

};


#endif //AMOUNTOFWORDSPART2_FILEWRITER_H
