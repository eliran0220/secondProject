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
protected:
    int evaluatedNodes;
    MyPriorityQueue<T>* openList;

public:
    Searcher(MyPriorityQueue<T>* myPriorityQueue) {
        this->openList = myPriorityQueue;
        this->evaluatedNodes = 0;
    }
    virtual vector<State<T>*> search(Searchable<T> searchable) = 0;

    virtual int openListSize() {
        this->openList.size();
    }

    virtual State <T>* popOpenList(){
        State<T>* temp = this->openList.poll();
        if (temp != nullptr) {
            this->evaluatedNodes++;
        }
        return temp;
    }

    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    virtual vector<State<T>> backTrace(State<T> state) {
        vector<State<T>> path;
        State<T> current = state;
        State<T> temp;
        while (current != nullptr) {
            path.push_back(current);
            current = current.getCameFrom();
        }
        return path;
    }

    ~Searcher() {
        delete(this->openList);
    }

};

#endif //SECONDPROJECT_SEARCHER_H
