//
// Created by afik on 1/12/19.
//

#ifndef SECONDPROJECT_MYUNORDEREDSET_H
#define SECONDPROJECT_MYUNORDEREDSET_H

#include <iostream>
#include <unordered_set>

#include "../searchPackage/State.h"

using std::unordered_set;
using std::iterator;

template<class T>
//class MyUnorderedSet : public unordered_set<State<T>*,statePHash<T>, stateComp<T>>{
class MyUnorderedSet : public unordered_set<State<T>*,statePHash<T>, stateComp<T>>{
    //unordered_set<State<T>*,statePHash<T>, stateComp<T>> set;
public:
    //MyUnorderedSet() = default;

    bool contains(State<T> *state) const {
        //for (State<T>* stateIt : this) {
           // if (*stateIt->getData() == *state->getData()) {
            //    return true;
          //  }
        //}
        //auto it = std::find(this->begin(), this->end(), state);
        auto search = this->find(state);

        //return this->find(state) != this->end();
        return false;
     //   return false;
    }

    State<T>* getState(State<T>* state) {
        State<T>* stateInSet = nullptr;
        auto it = this->find(state);
        stateInSet = it.operator*();
        return stateInSet;
    }

    void insertState(State<T>* state) {
        this->insert(state);
        //this->insert(state);
    }

    void remove(State<T>* state) {
        this->erase(state);
    }
};

#endif //SECONDPROJECT_MYUNORDEREDSET_H
