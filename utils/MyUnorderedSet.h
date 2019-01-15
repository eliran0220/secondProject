//
// Created by afik on 1/12/19.
//

#ifndef SECONDPROJECT_MYUNORDEREDSET_H
#define SECONDPROJECT_MYUNORDEREDSET_H

#include <iostream>
#include <unordered_set>
#include <vector>

#include "../searchPackage/State.h"

using std::unordered_set;
using std::iterator;

template<class T>

class MyUnorderedSet : public unordered_set<State<T>*,statePHash<T>, stateComp<T>> {
    std::vector<State<T>*> states;

public:
    bool contains(State<T> *state) const {
        return this->find(state) != this->end();
    }

    State<T>* getState(State<T>* state) {
        State<T>* stateInSet = nullptr;
        auto it = this->find(state);
        stateInSet = it.operator*();
        return stateInSet;
    }

    void insertState(State<T>* state) {
        this->insert(state);
        this->states.push_back(state);
    }

    void remove(State<T>* state) {
        this->erase(state);
    }

    void initialize() {
        this->clear();
        this->states.clear();
    }

    std::vector<State<T>*> getPointersStates() { return this->states;}
};

#endif //SECONDPROJECT_MYUNORDEREDSET_H
