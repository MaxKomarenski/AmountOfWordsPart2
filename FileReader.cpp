//
// Created by Victor on 30.04.2018.
//

#include "FileReader.h"

void FileReader::read_from_file(Queue &queue) {
    std::vector <std::string> words; // Vector to hold our words we read in.

    std::string str;

    std::ifstream fin("here.txt"); // Open it up!
    int i =0;
    std::string result;
    while (fin >> str) // Will read up to eof() and stop at every
    {                  // whitespace it hits. (like spaces!)

        std::remove_copy_if(str.begin(), str.end(),
                            std::back_inserter(result), //Store output
                            std::ptr_fun<int, int>(&std::ispunct)
        );

        if(result != ""){
            std::transform(str.begin(), str.end(), str.begin(), ::tolower); // make string lowercase
            words.push_back(result);
            result.clear();
        }

        i++;
        if(i >= block_size){
            queue.push(words);
            conditions.isData.notify_one();
            words.clear();
            i=0;
        }
    }
    queue.push(words);
    conditions.isData.notify_one();
    conditions.readingIsFinished = true;

    fin.close(); // Close that file!

}

FileReader::FileReader(int block_size) : block_size(block_size) {}

void FileReader::start(Queue &queue) {
    std::thread t(read_from_file, this, std::ref(queue));
    t.join();
}
