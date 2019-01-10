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

    State(T state) {
        this->state = state;
        // this->cameFrom = cameFrom;
    }


//template<class T>
//State<T>::~State() {
//    delete (this->cameFrom);
//}


    T getState() {
        return this->state;
    }


    bool Equals(State<T>* state) {
        if (state == this) {
            return true;
        }
        return false;
    }


    State<T>* getCameFrom() {
        return this->getCameFrom();
    }


    double getCost() {
        return  this->cost;
    }
    /*
    State(T state);

    T getState();

    double getCost();

    State<T>* getCameFrom();

    bool Equals(State<T>* state);
     */

   // ~State();
};


#endif //SECONDPROJECT_STATE_H
