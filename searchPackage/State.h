#ifndef STATE_H
#define STATE_H


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
        return *this->data == *data->getData();
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
    bool operator()(State<T> *const &left, State<T> *const &right) const {
        return *(left->getData()) == *(right->getData());
    }
};

#endif
