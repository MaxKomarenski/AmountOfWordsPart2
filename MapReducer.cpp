//
// Created by User on 30.04.2018.
//

#include "MapReducer.h"

std::map<std::string, int> MapReducer::merge_in_one_map(const std::vector<std::map <std::string, int>> &maps){
    std::map<std::string, int> merged_map;

    for(auto map:maps){
        for (auto const& element : map) {
            if(merged_map.count(element.first)){
                merged_map[element.first]+=element.second;
            }else{
                merged_map[element.first] = element.second;
            }

        }
    }
    return merged_map;
}