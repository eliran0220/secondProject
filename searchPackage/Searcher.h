//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHER_H
#define SECONDPROJECT_SEARCHER_H

using namespace std;

#include <queue>
#include "State.h"
#include "Searchable.h"
#include "set"
template<class T, class Solution>
class Searcher {

    priority_queue<T> priorityQueue;

public:
    virtual Solution search(Searchable<T> searchable) =0;

    virtual int openListSize() = 0;

    virtual State <T> popOpenList() =0;

};

#endif //SECONDPROJECT_SEARCHER_H
