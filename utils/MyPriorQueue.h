//
// Created by afik on 1/11/19.
//

#ifndef SECONDPROJECT_MYPRIORQUEUE_H
#define SECONDPROJECT_MYPRIORQUEUE_H

#include <queue>
#include <set>
#include "../searchPackage/State.h"


using namespace std;


template<class T, class compare>
class MyPriorQueue : public priority_queue<State<T>*,vector<State<T>*>,compare>{
    set<State<T>*> setOfStates;

public:
    void pushState(State<T>* state) {
        this->push(state);
        this->setOfStates.insert(state);
    }

    int sizeQueue() {
        return (int)this->size();
    }

    State<T>* poll() {
        if (this->sizeQueue() > 0) {
            State<T>* state = this->top();
            this->pop();
            this->setOfStates.erase(state);
            return state;
        }
        return nullptr;
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
            temp = this->poll();
        }
        for (int i = 0; i < (int)states.size(); ++i) {
            this->pushState(states[i]);
        }
    }
};


#endif //SECONDPROJECT_MYPRIORQUEUE_H
