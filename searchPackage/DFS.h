//
// Created by eliran on 1/11/19.
//

#ifndef SECONDPROJECT_DFS_H
#define SECONDPROJECT_DFS_H

#include "Searcher.h"
#include <set>
#include <stack>
#include "../utils/MyUnorderedSet.h"


template <class T>
class DFS: public Searcher<T> {
    stack<State<T>*> openList;
    MyUnorderedSet<T> statesInOpenList;

public:
    DFS() : Searcher<T>() {}

    State <T>* popOpenList(){
        State<T>* temp = this->openList.top();
        this->openList.pop();
        if (temp != nullptr) {
            this->evaluatedNodes++;
            this->statesInOpenList.remove(temp);
        }
        //this->statesInOpenList.erase(temp);
        return temp;
    }

    void pushState(State <T>* state) {
        this->statesInOpenList.insertState(state);
        this->openList.push(state);
    }


    void initialize() {
        while (!this->openList.empty()) {
            this->openList.pop();
        }
        this->statesInOpenList.clear();
        this->evaluatedNodes = 0;
    }

    vector<State<T>*> search(Searchable<T>* searchable) {
        State<T> *initialState = searchable->getInitialState();
        pushState(initialState); // push the initial state
        MyUnorderedSet<T> closed;
        vector<State<T> *> path;
        State<T> *goalState = searchable->getGoalState();
        while (!this->openList.empty()) {
            State<T> *topInStack = this->popOpenList();
            // אם הוא נמצא ב closed
            if (!closed.contains(topInStack)) {
                closed.insertState(topInStack);
            }
            if (topInStack->Equals(goalState)) {
                path = this->backTrace(topInStack);
                this->calculateEvaluatedNodes(this->statesInOpenList, path, closed);
                //this->initialize();
                return path;
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(topInStack);
            for (State<T> *state : successors) {
                // אם הוא לא נמצא ב closed וגם ב open
                if (!closed.contains(state)&& !this->statesInOpenList.contains(state)) {
                    state->setCameFrom(topInStack);
                    state->setCostPath(
                            topInStack->getCost() + state->getPositionCost());
                    pushState(state);
                }
            }
        }
        //this->initialize();
        return path;
    }
};
#endif //SECONDPROJECT_DFS_H
