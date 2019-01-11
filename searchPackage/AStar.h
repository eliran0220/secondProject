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

    double func(State<T> state) {
        return state.getCost() + state.getPositionCost();
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
                    state->setFCost(func(state));
                    this->openList->push(state);
                } else {
                    // מנסים למצוא האם יש דרך יותר טובה להגיע ב"חזרה לאחור"
                    double updatedCostPath = 0;
                    State<T> temp = state;
                    State<T> tempN = n;
                    state->setCameFrom(n);
                    while (tempN != nullptr) {
                        updatedCostPath += state->getCost();
                        tempN = tempN->getCameFrom();
                    }
                    if (updatedCostPath < state->getCost()) {
                        state->setCameFrom(n);
                        this->openList->eraseAndPush(state);
                    } else if (!(closed.count(state) >= 1)) {
                        this->openList->push(state);
                    }

                }
            }
        }
    }
};


#endif //SECONDPROJECT_ASTAR_H
