//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_BESTFIRSTSEARCH_H
#define SECONDPROJECT_BESTFIRSTSEARCH_H


#include "Searcher.h"
template <class Solution, class Searchable>
class BestFirstSearch : public Searcher<Solution,Searchable> {
    Solution search(Searchable searchable);

};




#endif //SECONDPROJECT_BESTFIRSTSEARCH_H
