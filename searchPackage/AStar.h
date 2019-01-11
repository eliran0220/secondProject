//
// Created by eliran on 1/11/19.
//

#ifndef SECONDPROJECT_ASTAR_H
#define SECONDPROJECT_ASTAR_H

#include "Searcher.h"
#include "../utils/MinPriorityQueue.h"

template<class T>

class AStar : public Searcher<T> {
public:
    AStar() : Searcher<T>(new MinPriorityQueue<T>) {}

    double func(State<T> *state) {
        return state->getCost() + state->getPositionCost();
    }

    vector<State<T> *> search(Searchable<T> *searchable) {

        State<T> *initialState = searchable->getInitialState();
        this->openList->push(initialState); // push the initial state
        set<State<T> *> closed;
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
                    double fCost = this->func(state);
                    state->setFCost(fCost);
                    this->openList->push(state);
                } else {


                }
            }
        }
    }
};


#endif //SECONDPROJECT_ASTAR_H
