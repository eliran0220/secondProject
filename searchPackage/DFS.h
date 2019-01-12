//
// Created by eliran on 1/11/19.
//

#ifndef SECONDPROJECT_DFS_H
#define SECONDPROJECT_DFS_H

#include "Searcher.h"
#include <set>
#include <stack>

template <class T>
class DFS: public Searcher<T> {
    stack<State<T>*> openList;
    set<State<T>*> statesInOpenList;

public:
    DFS() : Searcher<T>() {}

    State <T>* popOpenList(){
        State<T>* temp = this->openList.top();
        this->openList.pop();
        if (temp != nullptr) {
            this->evaluatedNodes++;
            this->statesInOpenList.erase(temp);
        }
        //this->statesInOpenList.erase(temp);
        return temp;
    }

    void pushState(State <T>* state) {
        this->statesInOpenList.insert(state);
        this->openList.push(state);
    }


    vector<State<T>*> search(Searchable<T>* searchable) {
        State<T> *initialState = searchable->getInitialState();
        pushState(initialState); // push the initial state
        set<State<T>*> closed;
        vector<State<T> *> path;
        State<T> *goalState = searchable->getGoalState();
        while (this->openList.size() > 0) {
            State<T> *topInStack = this->popOpenList();
            // אם הוא נמצא ב closed
            if (closed.count(topInStack) < 1) {
                closed.insert(topInStack);
            }
            if (topInStack->Equals(goalState)) {
                path = this->backTrace(topInStack);
                this->calculateEvaluatedNodes(this->statesInOpenList, path, closed);
                return path;
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(topInStack);
            for (State<T> *state : successors) {
                // אם הוא לא נמצא ב closed וגם ב open
                if ((closed.count(state) < 1)&& (this->statesInOpenList.count(state) < 1)) {
                    state->setCameFrom(topInStack);
                    pushState(state);
                }
            }
        }
    }
};
#endif //SECONDPROJECT_DFS_H
