//
// Created by afik on 1/10/19.
//

#ifndef SECONDPROJECT_BFS_H
#define SECONDPROJECT_BFS_H

#include "Searcher.h"
#include "../utils/RegularQueue.h"

template <class T>
class BFS: public Searcher<T> {
    BFS() : Searcher<T>(new RegularQueue<T>) {}

    vector<State<T>*> search(Searchable<T>* searchable) {
        State<T> *initialState = searchable->getInitialState();
        this->openList->push(initialState); // push the initial state
        set<State<T>*> closed;
        State<T> *goalState = searchable->getGoalState();
    }
};


#endif //SECONDPROJECT_BFS_H
