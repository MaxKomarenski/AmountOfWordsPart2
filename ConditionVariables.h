//
// Created by User on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_CONDITIONVARIABLES_H
#define AMOUNTOFWORDSPART2_CONDITIONVARIABLES_H

#include <condition_variable>
struct ConditionVariables{
    std::mutex data_mutex;
    std::mutex reduce_mutex;
    std:: condition_variable isData;
    std:: condition_variable queueHasMap;
    std:: condition_variable reduce_finished;
    bool readingIsFinished = false;
    bool merging_in_process = false;
};



extern ConditionVariables  conditions;
#endif //AMOUNTOFWORDSPART2_CONDITIONVARIABLES_H
