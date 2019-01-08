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
    State<T> cameFrom;

public:
    State(T state);

    T getState();

    bool Equals(T state);

    virtual ~State();
};


#endif //SECONDPROJECT_STATE_H
