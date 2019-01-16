#ifndef BESTFIRSTSEARCH_H
#define BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "../utils/MyPriorQueue.h"

/**
 * template <class T>
 * @tparam T given T
 */
template<class T>
struct compMin {
    /**
     * Function name: operator
     * The function operation: performs checking operation between path value of
     * two states.
     * @param l given State<T> *
     * @param r State<T> *
     * @return bool
     */
    bool operator()(State<T> *l, State<T> *r) {
        return l->getCost() > r->getCost();
    }
};

/**
 * BestFirstSearch class, implements Searcher
 * @tparam T given T
 */
template<class T>
class BestFirstSearch : public Searcher<T> {
    MyPriorQueue<T, compMin<T>> openList;

public:
    /**
     * Function name: BestFirstSearch
     * The function operation: constructor
     */
    BestFirstSearch() : Searcher<T>() {}

    /**
     * Function name: popOpenList
     * The function operation: pops a  State<T> * from the list
     * @return  State<T> *
     */
    State<T> *popOpenList() {
        State<T> *temp = this->openList.poll();
        return temp;
    }

    /**
     * Function name: initialize
     * The function operation: initialzies the list and evalutted nodes
     */
    void initialize() {
        this->openList.clear();
        this->evaluatedNodes = 0;
    }

    /**
     * Function name: search
     * The function operation: performs the BestFirstSearch algorithm,
     * each time pops a state from the priority queue, and checks if it's
     * the goal state, if so, terminates and returns the path.
     * if not, gets all the successors of the state and calculates for each
     * one the cost, and pushes them to the priority queue.
     * @param searchable given Searchable<T>*
     * @return vector<State<T> *>
     */
    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *initialState = searchable->getInitialState();
        vector<State<T> *> path;
        this->openList.pushState(initialState);// push the initial state
        MyUnorderedSet<T> closed;
        State<T> *goalState = searchable->getGoalState();
        while (this->openList.sizeQueue() > 0) {
            State<T> *topInQueue = this->popOpenList();
            if (!closed.contains(topInQueue)) {
                closed.insertState(topInQueue);
            }
            if (topInQueue->Equals(goalState)) {
                path = this->backTrace(topInQueue);
                this->calculateEvaluatedNodes(this->openList.getSetInQueue(),
                                              path, closed);
                return path;
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(
                    topInQueue);
            for (State<T> *state : successors) {
                if (!closed.contains(state) &&
                    !(this->openList.contains(state))) {
                    state->setCameFrom(topInQueue);
                    state->setCostPath(
                            topInQueue->getCost() + state->getPositionCost());
                    this->openList.pushState(state);

                } else {
                    // if the cost path is a less than the previous path.
                    if (this->openList.contains(state) &&
                        (topInQueue->getPositionCost() + state->getCost()) <
                        state->getPositionCost()) {
                        state->setCameFrom(state);
                        state->setCostPath(topInQueue->getPositionCost() +
                                           state->getCost());
                        this->openList.eraseAndPush(state);
                    }
                }
            }
        }
        return path;
    }
};


#endif
