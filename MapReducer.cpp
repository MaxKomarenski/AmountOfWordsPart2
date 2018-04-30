//
// Created by User on 30.04.2018.
//

#include "MapReducer.h"

std::map<std::string, int> MapReducer::merge_in_one_map(std::map<std::string, int> map1, std::map<std::string, int> map2){


        for (auto const& element : map2) {
            if(map1.count(element.first)){
                map1[element.first]+=element.second;
            }else{
                map1[element.first] = element.second;
            }

        }

    return map1;
}