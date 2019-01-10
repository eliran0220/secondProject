//
// Created by eliran on 1/11/19.
//

#ifndef SECONDPROJECT_DFS_H
#define SECONDPROJECT_DFS_H

#include "Searcher.h"
#include "../utils/MyPriorityStack.h"

template <class T>
class DFS: public Searcher<T> {
public:
    DFS() : Searcher<T>(new MyPriorityStack<T>) {}
    vector<State<T>*> search(Searchable<T>* searchable) {
        State<T> *initialState = searchable->getInitialState();
        this->openList->push(initialState); // push the initial state
        set<State<T>*> closed;
        State<T> *goalState = searchable->getGoalState();
        while (this->openListSize() > 0) {
            State<T> *topInStack = this->popOpenList();
            closed.insert(topInStack);
            if (topInStack->Equals(goalState)) {
                return this->backTrace(topInStack);
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(topInStack);
            for (State<T> *state : successors) {
                if (!(closed.count(state) >= 1)) {
                    state->setCameFrom(topInStack);
                    closed.insert(state);
                    this->openList->push(state);
                }
            }
        }
    }
};
#endif //SECONDPROJECT_DFS_H
