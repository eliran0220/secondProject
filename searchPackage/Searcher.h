//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHER_H
#define SECONDPROJECT_SEARCHER_H

using namespace std;

#include <queue>
#include "State.h"
#include "Searchable.h"

template<class T>
class Searcher {
protected:
    int evaluatedNodes;

public:
    virtual vector<State<T>*> search(Searchable<T>* searchable) = 0;

    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    vector<State<T>*> backTrace(State<T>* state) {
        vector<State<T>*> path;
        State<T>* current = state;
        State<T>* temp;
        while (current != nullptr) {
            path.push_back(current);
            current = current->getCameFrom();
        }
        return path;
    }
};

#endif //SECONDPROJECT_SEARCHER_H
