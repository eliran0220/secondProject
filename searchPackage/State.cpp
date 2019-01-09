//
// Created by eliran on 1/8/19.
//

#include "State.h"

template<class T>
State<T>::State(T state, State<T>* cameFrom) {
    this->state = state;
    this->cameFrom = cameFrom;
}


template<class T>
State<T>::~State() {
    delete (this->cameFrom);
}

template<class T>
T State<T>::getState() {
    return this->state;
}

template <class T>
bool State<T>::Equals(State<T> state) {
    if (state.getState() == this->state) {
        return true;
    }
    return false;
}

template <class T>
State<T>* State<T>::getCameFrom() {
    return this->getCameFrom();
}

template <class T>
double State<T>::getCost() {
    return  this->cost;
}




