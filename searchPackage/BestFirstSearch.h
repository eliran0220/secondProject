//
// Created by eliran on 1/9/19.
//

#ifndef SECONDPROJECT_BESTFIRSTSEARCH_H
#define SECONDPROJECT_BESTFIRSTSEARCH_H


#include "Searcher.h"

template<class T, class Solution>
class BestFirstSearch : public Searcher<T, Solution> {

private:
    queue<State<T>> openList;
    int evaluatedNodes;

public:
    BestFirstSearch();
    Solution search(Searchable<T> searchable) override;
    int openListSize() override;
    State<T> popOpenList() override;


};


#endif //SECONDPROJECT_BESTFIRSTSEARCH_H
