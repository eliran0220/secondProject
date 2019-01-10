//
// Created by eliran on 1/9/19.
//

#ifndef SECONDPROJECT_BESTFIRSTSEARCH_H
#define SECONDPROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"

template<class T, class Solution>
class BestFirstSearch{

private:
    queue<State<T>> openList;
    int evaluatedNodes;

public:
    BestFirstSearch();
    Solution search(Searchable<T> searchable);
    int openListSize();
    State<T> popOpenList();
    list<State<T>> backTrace();
};


#endif //SECONDPROJECT_BESTFIRSTSEARCH_H
