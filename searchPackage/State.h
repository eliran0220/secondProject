//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_STATE_H
#define SECONDPROJECT_STATE_H


template<class T>
class State {
private:
    T state;
    double cost;
    State<T>* cameFrom;

public:
    State(T state, State<T>* cameFrom);

    T getState();

    double getCost();

    State<T>* getCameFrom();

    bool Equals(State<T> state);

    ~State();
};


#endif //SECONDPROJECT_STATE_H
