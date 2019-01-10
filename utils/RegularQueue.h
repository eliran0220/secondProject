//
// Created by afik on 1/10/19.
//

#ifndef SECONDPROJECT_REGULARQUEUE_H
#define SECONDPROJECT_REGULARQUEUE_H


#include <queue>
#include <set>
#include "MyPriorityQueue.h"

using namespace std;;

template <class T>
class RegularQueue : public MyPriorityQueue<T> {

    queue<State<T>*> priorityQueue;
    int sizeQueue;
    set<State<T>*> setOfStates;

public:
    RegularQueue(){
        this->sizeQueue= 0;
    }

    void push(State<T>* state) {
        priorityQueue.push(state);
        this->setOfStates.insert(state);
        this->sizeQueue++;
    }

    int size() {
        return this->sizeQueue;
    }

    State<T>* poll() {
        if (this->sizeQueue > 0) {
            State<T>* state = priorityQueue.front();
            priorityQueue.pop();
            this->setOfStates.erase(state);
            this->sizeQueue--;
            return state;
        }
        return nullptr;
    }

    bool isEmpty() {
        if (this->sizeQueue == 0) {
            return true;
        }
        return false;
    }

    bool contains(State<T>* state) {
        if (this->setOfStates.count(state) == 1) {
            return true;
        }
        return false;
    }

    void eraseAndPush(State<T>* state) {
        vector<State<T>*> states;
        State<T>* temp;
        temp = this->poll();
        while (temp != nullptr) {
            if (!state->Equals(temp)) {
                states.push_back(temp);
            } else {
                break;
            }
        }
        for (int i = 0; i < (int)states.size(); ++i) {
            this->push(states[i]);
        }
    }
};

#endif //SECONDPROJECT_REGULARQUEUE_H
