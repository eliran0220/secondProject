#ifndef DFS_H
#define DFS_H

#include "Searcher.h"
#include <set>
#include <stack>
#include "../utils/MyUnorderedSet.h"

/**
 * template <class T>
 * @tparam T given T
 */
template<class T>
/**
 * DFS class, implemets Searcher
 * @tparam T given T
 */
class DFS : public Searcher<T> {
    stack<State<T> *> openList;
    MyUnorderedSet<T> statesInOpenList;

public:
    /**
     * Function name: BFS
     * The function operation: constructor
     */
    DFS() : Searcher<T>() {}

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
            this->statesInOpenList.remove(temp);
        }
        return temp;
    }

    /**
     * Function name: pushState
     * The function operation: given a state, pushes it to the list
     * @param state given State<T> *
     */
    void pushState(State<T> *state) {
        this->statesInOpenList.insertState(state);
        this->openList.push(state);
    }

    /**
     * Function name: initialize
     * The function operation: initialzies the list and evalutted nodes
     */
    void initialize() {
        while (!this->openList.empty()) {
            this->openList.pop();
        }
        this->statesInOpenList.clear();
        this->evaluatedNodes = 0;
    }

    /**
     * Function name: search
     * The function operation: performs the DFS algorithm,
     * each time pops a state from the stack, and checks if it's
     * the goal state, if so, terminates and returns the path.
     * if not, gets all the successors of the state and calculates for each
     * one the cost, and pushes them to the stack.
     * @param searchable given Searchable<T>*
     * @return vector<State<T> *>
     */
    vector<State<T> *> search(Searchable<T> *searchable) {
        State<T> *initialState = searchable->getInitialState();
        pushState(initialState); // push the initial state
        MyUnorderedSet<T> closed;
        vector<State<T> *> path;
        State<T> *goalState = searchable->getGoalState();
        while (!this->openList.empty()) {
            State<T> *topInStack = this->popOpenList();
            if (!closed.contains(topInStack)) {
                closed.insertState(topInStack);
            }
            if (topInStack->Equals(goalState)) {
                path = this->backTrace(topInStack);
                this->calculateEvaluatedNodes(this->statesInOpenList, path,
                                              closed);
                return path;
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(
                    topInStack);
            for (State<T> *state : successors) {
                if (!closed.contains(state) &&
                    !this->statesInOpenList.contains(state)) {
                    state->setCameFrom(topInStack);
                    state->setCostPath(
                            topInStack->getCost() + state->getPositionCost());
                    pushState(state);
                }
            }
        }
        return path;
    }
};

#endif
