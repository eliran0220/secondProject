//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_STATE_H
#define SECONDPROJECT_STATE_H


#include "../utils/Point.h"

template<class T>
class State {
private:
    T state;
    double cost;
    double pathCost;
    double heuristicCost;
    State<T>* cameFrom;
    Point* position;

public:

    State(T state, double cost, int x, int y) {
        this->state = state;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->pathCost = cost;
        this->heuristicCost = 0;
        this->position = new Point(x,y);
    }

    void setCostPath(double cost) {
        this->pathCost = cost;
    }
    int getX() {
        return this->position->getX();
    }

    int getY() {
        return this->position->getY();
    }

    T getState() {
        return this->state;
    }


    bool Equals(State<T>* state) {
        if (state->getX() == this->getX() && state->getY() == this->getY()) {
            return true;
        }
        return false;
    }


    State<T>* getCameFrom() {
        return this->cameFrom;
    }

    void setCameFrom(State<T>* state) {
        this->cameFrom = state;
    }

    double getPositionCost() {
        return this->cost;
    }

    double getCost() {
        return this->pathCost;
    }

    double setHeuristicCost(double cost) {
        this->heuristicCost = cost;
    }

    double getHeuristicCost() {
        return this->heuristicCost;
    }

    ~State() {
        delete (this->position);
    }
};


#endif //SECONDPROJECT_STATE_H
