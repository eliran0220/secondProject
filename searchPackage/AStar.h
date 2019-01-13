#ifndef ASTAR_H
#define ASTAR_H

#include "Searcher.h"
#include <math.h>
#include "../utils/MyPriorQueue.h"

/**
 * compareMinWithHeuristicCost struct is used so t
 * @tparam T
 */
template<class T>
struct compareMinWithHeuristicCost {
    bool operator()(State<T> *l, State<T> *r) {
        return l->getCost() + l->getHeuristicCost() >
               r->getCost() + r->getHeuristicCost();
    }
};


template<class T>
class AStar : public Searcher<T> {
    MyPriorQueue<T, compareMinWithHeuristicCost<T>> openList;

public:
    AStar() : Searcher<T>() {}

    double heuristicFunc(State<Point*> *state, State<Point*> *goalState) {
        return state->getData()->getDistance(goalState->getData());
    }

    State<T> *popOpenList() {
        State<T> *temp = this->openList.top();
        this->openList.pop();
        if (temp != nullptr) {
            this->evaluatedNodes++;
        }
        return temp;
    }

    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *initialState = searchable->getInitialState();
        this->openList.pushState(initialState); // push the initial state
        MyUnorderedSet<T> closed;
        State<T> *goalState = searchable->getGoalState();
        while (!this->openList.empty()) {
            State<T> *topInQueue = this->popOpenList();
            if (topInQueue->Equals(goalState)) {
                return this->backTrace(topInQueue);
            }
            if (closed.contains(topInQueue)) {
                continue;
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(
                    topInQueue);

            for (State<T> *state : successors) {
                if (!this->openList.contains(state)) {
                    state->setCostPath(
                            topInQueue->getCost() + state->getPositionCost());
                    state->setCameFrom(topInQueue);
                    state->setHeuristicCost(heuristicFunc(state, goalState));
                    this->openList.pushState(state);
                }
            }
            closed.insertState(topInQueue);
        }
    }
};


#endif
