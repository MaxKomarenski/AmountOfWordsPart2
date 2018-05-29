//
// Created by MaxKomarenski
//

#include "Configuration.h"

const std::string &Configuration::getFileReadToken() const {
    return fileReadToken;
}

const std::string &Configuration::getFileWriteSortedByLettersToken() const {
    return fileWriteSortedByLettersToken;
}

const std::string &Configuration::getFileWriteSortedByAmountToken() const {
    return fileWriteSortedByAmountToken;
}

const std::string &Configuration::getFileRead() const {
    return fileRead;
}

void Configuration::setFileRead(const std::string &fileRead) {
    Configuration::fileRead = fileRead;
}

const std::string &Configuration::getFileWriteSortedByLetters() const {
    return fileWriteSortedByLetters;
}

void Configuration::setFileWriteSortedByLetters(const std::string &fileWriteSortedByLetters) {
    Configuration::fileWriteSortedByLetters = fileWriteSortedByLetters;
}

const std::string &Configuration::getFileWriteSortedByAmount() const {
    return fileWriteSortedByAmount;
}

void Configuration::setFileWriteSortedByAmount(const std::string &fileWriteSortedByAmount) {
    Configuration::fileWriteSortedByAmount = fileWriteSortedByAmount;
}



std::string Configuration::parseString(std::string input) {
    char* endPtr;
    int i=0;
    while (input.at(i) != '\"'){
        i++;
        if(input.at(i)=='\"'){
            i++;
            std::string s(input, i, input.size());
            s.erase(s.size()-1, 1);
            return s;

        }
        if(i>=input.size()){
            std::cout<<"Error with parsing string "<<input
                     << "\n.You missed \"param\"\nCorrect string must look like: "
                     <<"File from:\"text.txt\"\nCorrect it and restart program"<<std::endl;
            throw EIO;
        }
    }

}

std::ostream &operator<<(std::ostream &os, const Configuration &configuration) {
    os << "\nfileRead: "
       << configuration.fileRead << "\nfileWriteSortedByLetters: " << configuration.fileWriteSortedByLetters
       << "\nfileWriteSortedByAmount: " << configuration.fileWriteSortedByAmount<<"\n";
    return os;
}

void Configuration::configure(Configuration& conf){

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


