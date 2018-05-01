//
// Created by User on 30.04.2018.
//

#ifndef AMOUNTOFWORDSPART2_CONDITIONVARIABLES_H
#define AMOUNTOFWORDSPART2_CONDITIONVARIABLES_H

#include <condition_variable>
struct ConditionVariables{
    std::mutex data_mutex;
    std:: condition_variable isData;
    std:: condition_variable queueHasMap;
    std:: condition_variable wc_ready;
    bool readingIsFinished = false;
};



extern ConditionVariables  conditions;
#endif //AMOUNTOFWORDSPART2_CONDITIONVARIABLES_H
