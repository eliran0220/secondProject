#ifndef SECONDPROJECT_BFS_H
#define SECONDPROJECT_BFS_H

#include "Searcher.h"
#include <set>

template <class T>
class BFS: public Searcher<T> {
    queue<State<T>*> openList;
    set<State<T>*> statesInOpenList;

public:
    BFS() : Searcher<T>() {}

    State <T>* popOpenList(){
        State<T>* temp = this->openList.front();
        this->openList.pop();
        if (temp != nullptr) {
            this->evaluatedNodes++;
            this->statesInOpenList.erase(temp);
        }
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
            State<T> *topInQueue = this->popOpenList();
            if (closed.count(topInQueue) < 1) {
                closed.insert(topInQueue);
            }
            if (topInQueue->Equals(goalState)) {
                path = this->backTrace(topInQueue);
                this->calculateEvaluatedNodes(this->statesInOpenList, path, closed);

                return path;
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(topInQueue);
            for (State<T> *state : successors) {
                if ((closed.count(state) < 1)&& (this->statesInOpenList.count(state) < 1)) {
                    state->setCameFrom(topInQueue);
                    pushState(state);
                }
            }
        }
    }
};


#endif //SECONDPROJECT_BFS_H
