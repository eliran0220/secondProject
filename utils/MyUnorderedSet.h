#ifndef MYUNORDEREDSET_H
#define MYUNORDEREDSET_H

#include <iostream>
#include <unordered_set>
#include <vector>

#include "../searchPackage/State.h"

using std::unordered_set;
using std::iterator;

template<class T>

/**
 *
 * MyUnorderedSet class
 *
 * @tparam T
 */
class MyUnorderedSet
        : public unordered_set<State<T> *, statePHash<T>, stateComp<T>> {
    std::vector<State<T> *> states;

public:
    /**
     * Function name: contains.
     * The function operation : check if a given state exists in the set.
     * @param state
     * @return
     */
    bool contains(State<T> *state) const {
        return this->find(state) != this->end();
    }

    /**
     * Function name: getState.
     * The function operation : check if a given state exists in the set.
     * @param state
     * @return
     */
    State<T> *getState(State<T> *state) {
        State<T> *stateInSet = nullptr;
        auto it = this->find(state);
        stateInSet = it.operator*();
        return stateInSet;
    }

    /**
     * Function name: insertState
     * The function operation: given a state, inserts it to the set
     * @param state given state
     */

    void insertState(State<T> *state) {
        this->insert(state);
        this->states.push_back(state);
    }

    /**
     * Function name: remove
     * The function operation: given a state, uses erase on it
     * @param state
     */
    void remove(State<T> *state) {
        this->erase(state);
    }

    /**
     * Function name: initialize
     * The function operation: clears all the set
     */
    void initialize() {
        this->clear();
        this->states.clear();
    }

    /**
     * Function name: getPointersState
     * The function operation : returns this state
     * @return
     */
    std::vector<State<T> *> getPointersStates() { return this->states; }
};

#endif
