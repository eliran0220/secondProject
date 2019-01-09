//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHER_H
#define SECONDPROJECT_SEARCHER_H

using namespace std;

#include <queue>
#include "ISearcher.h"
#include "State.h"

template<class T, class Solution, class Searchable>
class Searcher : public ISearcher<Solution, Searchable> {

private:
    queue<State<T>> openList;
    int evalutedNodes;

public:
    Searcher() =0;
    virtual int openListSize() =0;


protected:
    State <T> popOpenList();

};

#endif //SECONDPROJECT_SEARCHER_H
