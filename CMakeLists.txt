cmake_minimum_required(VERSION 3.9.6)
project(AmountOfWordsPart2)

set(CMAKE_CXX_STANDARD 14)

add_executable(AmountOfWordsPart2 main.cpp Queue.cpp Queue.h FileReader.cpp
        FileReader.h WordsCounter.cpp WordsCounter.h MapsQueue.cpp MapsQueue.h ThreadDispatcher.cpp ThreadDispatcher.h
        MapReducer.h MapReducer.cpp)