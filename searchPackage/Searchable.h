//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHABLE_H
#define SECONDPROJECT_SEARCHABLE_H

using namespace std;

#include <list>
#include "State.h"

template <class T> class Searchable  {
public:
    virtual State<T> getInitialState() =0;
    virtual State<T> getGoalState() =0;
    virtual list<State<T>> getAllPossibleStates(State<T>) = 0;

};
#endif //SECONDPROJECT_SEARCHABLE_H
