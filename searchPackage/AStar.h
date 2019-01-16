#ifndef ASTAR_H
#define ASTAR_H

#include "Searcher.h"
#include <math.h>
#include "../utils/MyPriorQueue.h"

/**
 * template <class T>
 * @tparam T given T
 */
template<class T>
struct compareMinWithHeuristicCost {
    /**
     * Function name: operator
     * The function operation: performs checking operation between path value of
     * two states and their heuristic cost
     * @param l given State<T>*
     * @param r given State<T>*
     * @return bool
     */
    bool operator()(State<T> *l, State<T> *r) {
        return l->getCost() + l->getHeuristicCost() >
               r->getCost() + r->getHeuristicCost();
    }
};

/**
 * AStar class, implements Searcher
 * @tparam T given T
 */
template<class T>
class AStar : public Searcher<T> {
    MyPriorQueue<T, compareMinWithHeuristicCost<T>> openList;

public:
    /**
     * Function name: AStar
     * The function operation: constructor
     */
    AStar() : Searcher<T>() {}

    /**
     * Function name: heuristicFunc
     * The function operation: calculates the heuristic value from a given
     * state to the goal state
     * @param state given State<T>*
     * @param goalState given State<T>*
     * @return double
     */
    double heuristicFunc(State<Point *> *state, State<Point *> *goalState) {
        return state->getData()->getDistance(goalState->getData());
    }

    /**
     * Function name: popOpenList
     * The function operation: pops a  State<T> * from the list
     * @return  State<T> *
     */
    State<T> *popOpenList() {
        State<T> *temp = this->openList.top();
        this->openList.pop();
        if (temp != nullptr) {
            this->evaluatedNodes++;
        }
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
     * The function operation: performs the known AStar algorithm,
     * each time pops a state from the priority queue, and checks if it's
     * the goal state, if so, terminates and returns the path.
     * if not, gets all the successors of the state and calculates for each
     * one the heuristic cost, and pushes them to the priority queue.
     * @param searchable given Searchable<T>*
     * @return vector<State<T> *>
     */
    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *initialState = searchable->getInitialState();
        this->openList.pushState(initialState); // push the initial state
        MyUnorderedSet<T> closed;
        State<T> *goalState = searchable->getGoalState();
        vector<State<T> *> path;
        while (!this->openList.empty()) {
            State<T> *topInQueue = this->popOpenList();
            if (topInQueue->Equals(goalState)) {
                path = this->backTrace(topInQueue);
                return path;
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
        return path;
    }
};


#endif
