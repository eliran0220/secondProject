//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHER_H
#define SECONDPROJECT_SEARCHER_H

using namespace std;

#include <queue>
#include "State.h"
#include "Searchable.h"
#include "../utils/MyPriorityQueue.h"
#include <set>

template<class T>
class Searcher {
    int evaluatedNodes;
    MyPriorityQueue<T> openList;

public:
    virtual State<T> search(Searchable<T> searchable) = 0;

    virtual int openListSize() {
        this->openList.size();
    }

    virtual State <T>& popOpenList(){
        State<T> temp = this->openList.poll();
        if (temp != nullptr) {
            this->evaluatedNodes++;
        }
        return temp;
    }

    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

};

#endif //SECONDPROJECT_SEARCHER_H
