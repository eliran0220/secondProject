#ifndef SECONDPROJECT_BFS_H
#define SECONDPROJECT_BFS_H

#include "Searcher.h"
#include "../utils/MyUnorderedSet.h"

template <class T>
class BFS: public Searcher<T> {
    queue<State<T>*> openList;
    MyUnorderedSet<T> statesInOpenList;

public:
    BFS() : Searcher<T>() {}

    State <T>* popOpenList(){
        State<T>* temp = this->openList.front();
        this->openList.pop();
        if (temp != nullptr) {
            this->evaluatedNodes++;
            this->statesInOpenList.remove(temp);
        }
        return temp;
    }

     void pushState(State <T>* state) {
        this->statesInOpenList.insertState(state);
        this->openList.push(state);
    }
    vector<State<T>*> search(Searchable<T>* searchable) {
        State<T> *initialState = searchable->getInitialState();
        pushState(initialState); // push the initial state
        MyUnorderedSet<T> closed;
        vector<State<T> *> path;
        State<T> *goalState = searchable->getGoalState();
        while (!this->openList.empty()) {
            State<T> *topInQueue = this->popOpenList();
            if (!closed.contains(topInQueue)) {
                closed.insertState(topInQueue);
            }
            if (topInQueue->Equals(goalState)) {
                path = this->backTrace(topInQueue);
                this->calculateEvaluatedNodes(this->statesInOpenList, path, closed);

                return path;
            }
            vector<State<T> *> successors = searchable->getAllPossibleStates(topInQueue);
            for (State<T> *state : successors) {
                if (!closed.contains(state)&& !this->statesInOpenList.contains(state)) {
                    state->setCameFrom(topInQueue);
                    pushState(state);
                }
            }
        }
    }
};


#endif //SECONDPROJECT_BFS_H
