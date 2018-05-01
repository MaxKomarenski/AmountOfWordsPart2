//
// Created by Victor on 01.05.2018.
//

#include <iostream>
#include "FileWriter.h"


void FileWriter::sort_by_letters_and_write_into_file(std::map<std::string, int> m, std::string filename){


    std::vector<std::string> retval;
    for (auto element : m) {
        retval.push_back(element.first);
    }
    std::sort( retval.begin(), retval.end() ); //sorts by letters

    std::ofstream outputFile;
    outputFile.open(filename);

    for (int i = 0; i < retval.size(); i++){
        std::string write_str = retval.at(i) + " - " + std::to_string(m[retval.at(i)]);
        outputFile << write_str << std::endl;
    }

    outputFile.close();
}

void FileWriter::sort_by_amount_and_write_into_file(std::map<std::string, int> m, std::string filename){
    std::vector<std::string> retval;
    for (auto const& element : m) {
        retval.push_back(element.first);
    }

    //sorts by values of map
    sort(retval.begin(),retval.end(),
         [&m](const std::string& a, const std::string& b){return m[a] > m[b]; });

    std::ofstream outputFile2;
    outputFile2.open(filename);

    for (int i = 0; i < retval.size(); i++){
        std::string write_str = retval.at(i) + " - " + std::to_string(m[retval.at(i)]);
        outputFile2 << write_str << std::endl;
    }

    outputFile2.close();
}