//
// Created by afik on 1/12/19.
//

#ifndef SECONDPROJECT_MYUNORDEREDSET_H
#define SECONDPROJECT_MYUNORDEREDSET_H

#include <iostream>

#include "../searchPackage/State.h"

template<class T>
class MyUnorderedSet {
    std::unordered_set<State<T>*,statePHash<T>, stateComp<T>> set;
public:
    MyUnorderedSet() = default;

    size_t size() {
        return this->set.size();
    }

    bool contains(State<T> *state) const {
        return set.find(state) != set.end();
    }

    void insert(State<T>* state) {
        this->set.insert(state);
    }

    void remove(State<T>* state) {
        this->set.erase(state);
    }
};
#endif //SECONDPROJECT_MYUNORDEREDSET_H
