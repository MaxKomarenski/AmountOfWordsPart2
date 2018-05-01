//
// Created by MaxKomarenski
//

#ifndef AMOUNTOFWORDS_CONFIGURATION_H
#define AMOUNTOFWORDS_CONFIGURATION_H
#include <string>
#include <iostream>


class Configuration {

private:
    const std::string fileReadToken = "File from:";
    const std::string fileWriteSortedByLettersToken = "Out by a:";
    const std::string fileWriteSortedByAmountToken = "Out by n:";

    std::string fileRead;
    std::string fileWriteSortedByLetters;
    std::string fileWriteSortedByAmount;


public:
    const std::string &getFileReadToken() const;

    const std::string &getFileWriteSortedByLettersToken() const;

    const std::string &getFileWriteSortedByAmountToken() const;

    const std::string &getFileRead() const;

    void setFileRead(const std::string &fileRead);

    const std::string &getFileWriteSortedByLetters() const;

    void setFileWriteSortedByLetters(const std::string &fileWriteSortedByLetters);

    const std::string &getFileWriteSortedByAmount() const;

    void setFileWriteSortedByAmount(const std::string &fileWriteSortedByAmount);

    std::string parseString(std::string input);

    friend std::ostream &operator<<(std::ostream &os, const Configuration &configuration);

};


#endif //AMOUNTOFWORDS_CONFIGURATION_H