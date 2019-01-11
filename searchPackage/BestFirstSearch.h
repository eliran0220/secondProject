//
// Created by eliran on 1/9/19.
//

#ifndef SECONDPROJECT_BESTFIRSTSEARCH_H
#define SECONDPROJECT_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "../utils/MyPriorQueue.h"


template <class T>
struct compMin
{
    bool operator()(State<T>* l, State<T>* r)
    {
        return l->getCost() > r->getCost();
    }
};

template<class T>
class BestFirstSearch : public Searcher<T> {
    MyPriorQueue<T,compMin<T>> openList;

public:
    BestFirstSearch() : Searcher<T>(){}

    State <T>* popOpenList(){
        State<T>* temp = this->openList.top();
        this->openList.pop();
        this->evaluatedNodes++;
        return temp;
    }

    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *initialState = searchable->getInitialState();
        this->openList.pushState(initialState); // push the initial state
        set<State<T> *> closed;
        State<T> *goalState = searchable->getGoalState();
        while (this->openList.sizeQueue() > 0) {
            State<T> *topInQueue = this->popOpenList();
            closed.insert(topInQueue);
            if (topInQueue->Equals(goalState)) {
                return this->backTrace(topInQueue);
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(topInQueue);
            for (State<T> *state : successors) {
                if (!(closed.count(state) >= 1) &&
                    !(this->openList.contains(state))) {
                    state->setCameFrom(topInQueue);
                    //state->setCostPath(topInQueue->getCost() + state->getCost());
                    // אם יש באג לשנות לשורה הקודמת
                    state->setCostPath(topInQueue->getCost() + state->getPositionCost());
                    this->openList.pushState(state);
                } else {
                    // if the cost path is a less than the previous path.
                    if (this->openList.contains(state) &&
                        (topInQueue->getPositionCost() + state->getCost()) <
                        state->getPositionCost()) {
                        state->setCameFrom(state);
                        state->setCostPath(topInQueue->getPositionCost() + state->getCost());
                        this->openList.eraseAndPush(state);
                    } else if (!(closed.count(state) >= 1)) {
                        this->openList.pushState(state);
                    }
                }
            }
        }
    }
};


#endif //SECONDPROJECT_BESTFIRSTSEARCH_H
