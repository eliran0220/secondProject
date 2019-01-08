//
// Created by eliran on 1/8/19.
//

#include "State.h"

template<class T>
State<T>::State(T state) {
    this->state = state;
}


template<class T>
State<T>::~State() {

}

template<class T>
T State<T>::getState() {
    return this->state;
}

template <class T> // later
bool State<T>::Equals(T state) {
    return false;
}




