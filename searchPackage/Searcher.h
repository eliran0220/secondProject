//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHER_H
#define SECONDPROJECT_SEARCHER_H

using namespace std;

#include <queue>
#include "ISearcher.h"
#include "State.h"
#include "Searchable.h"

template<class T, class Solution>
class Searcher {

public:
    virtual Solution search(Searchable<T> searchable);
    virtual int openListSize() =0;
    virtual State <T> popOpenList();

};

#endif //SECONDPROJECT_SEARCHER_H
