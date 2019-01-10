//
// Created by eliran on 1/9/19.
//

#ifndef SECONDPROJECT_BESTFIRSTSEARCH_H
#define SECONDPROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "../utils/MinPriorityQueue.h"

template<class T>
class BestFirstSearch: public Searcher<T> {


public:
    BestFirstSearch() : Searcher<T>(new MinPriorityQueue<T>) {}

    vector<State<T>*> search(Searchable<T>* searchable) {
        this->openList->push(
                searchable->getInitialState()); // push the initial state
        set<State<T>*> closed;
        State<T> *goalState = searchable->getGoalState();
        while (this->openListSize() > 0) {
            State<T> *n = this->popOpenList();
            closed.insert(n);
            if (n->Equals(goalState)) {
                return this->backTrace(n);
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(n);
            for (State<T> *state : successors) {
                if (!(closed.count(state) >= 1) &&
                    !(this->openList->contains(state))) {
                    state->setCameFrom(n);
                    state->setCostPath(n->getCost() + state->getCost());
                    this->openList->push(state);
                } else {
                    // if the cost path is a less than the previous path.
                    if (this->openList->contains(state) &&
                        n->getPositionCost() + state->getCost() <
                        state->getPositionCost()) {
                        state->setCameFrom(state);
                        state->setCostPath(n->getPositionCost() + state->getCost());
                        this->openList->eraseAndPush(state);
                    } else {
                        this->openList->push(state);
                    }
                }
            }
        }
    }
};


#endif //SECONDPROJECT_BESTFIRSTSEARCH_H
