#ifndef SECONDPROJECT_BFS_H
#define SECONDPROJECT_BFS_H

#include "Searcher.h"
#include <set>

template <class T>
class BFS: public Searcher<T> {
    queue<State<T>*> openList;

public:
    BFS() : Searcher<T>() {}

    State <T>* popOpenList(){
        State<T>* temp = this->openList.front();
        this->openList.pop();
        if (temp != nullptr) {
            this->evaluatedNodes++;
        }
        return temp;
    }

    vector<State<T>*> search(Searchable<T>* searchable) {
        State<T> *initialState = searchable->getInitialState();
        this->openList.push(initialState); // push the initial state
        set<State<T>*> closed;
        State<T> *goalState = searchable->getGoalState();
        while (this->openList.size() > 0) {
            State<T> *topInQueue = this->popOpenList();
            closed.insert(topInQueue);
            if (topInQueue->Equals(goalState)) {
                return this->backTrace(topInQueue);
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(topInQueue);
            for (State<T> *state : successors) {
                if (!(closed.count(state) >= 1)) {
                    state->setCameFrom(topInQueue);
                    closed.insert(state);
                    this->openList.push(state);
                }
            }
        }
    }
};


#endif //SECONDPROJECT_BFS_H
