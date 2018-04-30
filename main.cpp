#include <iostream>
#include "FileReader.h"
int main() {

    Queue queue;

    FileReader  fileReader(100);

    fileReader.read_from_file(queue);
    std::cout<<queue.getSize()<<"\n";


    std::vector<std::string> words;
    while (!(words = queue.pop()).empty()){
        for(auto s: words){
            std::cout<<s<<"\n";
        }
        std::cout<<"BLOCK:  \n";
    }

    return 0;
}