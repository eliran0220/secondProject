//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHABLE_H
#define SECONDPROJECT_SEARCHABLE_H

using namespace std;

#include <list>
#include <vector>
#include "State.h"

#define START_END_INDEXES 3

template <class T> class Searchable  {
public:
    virtual State<T>* getInitialState() =0;
    virtual State<T>* getGoalState() =0;
    virtual vector<State<T>*> getAllPossibleStates(State<T>* state) = 0;

};
#endif //SECONDPROJECT_SEARCHABLE_H
