//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_STATE_H
#define SECONDPROJECT_STATE_H


#include "../utils/Point.h"
#include <unordered_set>

template<class T>
class State {

private:
    T data;
    double cost;
    double pathCost;
    double heuristicCost;
    State<T> *cameFrom;

public:

    State(T data, double cost) {
        this->data = data;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->pathCost = cost;
        this->heuristicCost = 0;
    }

    void setCostPath(double cost) {
        this->pathCost = cost;
    }

    T getData() {
        return this->data;
    }


    bool Equals(State<T> *data) {
        return this->data == data->getData();
    }


    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    void setCameFrom(State<T> *state) {
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


};

template<class T>
struct statePHash {
    size_t operator()(State<T> *const &state) const {
        return std::hash<T>()(state->getData());
    }
};

template<class T>
struct stateComp {
    bool operator()(State<T> *const &l, State<T> *const &r) const {
        return l->getData() == r->getData();
    }
};

namespace std {
    template<class T>
    struct hash<State<T>> {
        size_t operator()(const State<T> &state) const {
            return hash<T>()(state.getData());
        }
    };
}

#endif //SECONDPROJECT_STATE_H
