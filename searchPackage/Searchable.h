//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHABLE_H
#define SECONDPROJECT_SEARCHABLE_H

using namespace std;

#include <list>
#include "State.h"

template <class SearchableItem, class T> class Searchable  {
    virtual State<T> getInitialState() =0;
    virtual State<T> getGoalState() =0;
    virtual list<T> getAllPossibleStates(State<T>);

};
#endif //SECONDPROJECT_SEARCHABLE_H
