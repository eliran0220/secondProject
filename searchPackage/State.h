
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

    /**
     * Function name: State
     * The function operation: costructor
     * @param data given data
     * @param cost given cost
     */
    State(T data, double cost) {
        this->data = data;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->pathCost = cost;
        this->heuristicCost = 0;
    }

    /**
     * Function name: setCostPath
     * The function operation: given a cost, sets it
     * @param cost
     */
    void setCostPath(double cost) {
        this->pathCost = cost;
    }

    /**
     * Function name: getData
     * The function operation: returns the data
     * @return T
     */
    T &getData() {
        return this->data;
    }

    /**
     * Function name: Equals
     * The function operation: returns true if the given data of the state
     * is equal to this data of state
     * @param data given data
     * @return bool
     */
    bool Equals(State<T> *data) {
        return *(this->data) == *(data->getData());
    }

    /**
     * Function name: getCameFrom
     * The function operation: returns who this came from
     * @return State<T>*
     */
    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    /**
     * Function name: setCameFrom
     * The function operation: given a state, we set this , came from state
     * @param state given state
     */
    void setCameFrom(State<T> *state) {
        this->cameFrom = state;
    }

    /**
     * Function name: getPositionCost
     * The function operation: returns this cost
     * @return double
     */
    double getPositionCost() {
        return this->cost;
    }

    /**
     * Function name: getCost
     * The function operation: returns this cost of path
     * @return double
     */
    double getCost() {
        return this->pathCost;
    }

    /**
     * Function name: setHeuristicCost
     * The function operation: given a cost, sets it to heuristicCost
     * @param cost given cost
     */
    void setHeuristicCost(double cost) {
        this->heuristicCost = cost;
    }

    /**
     * Function name: getHeuristicCost
     * The function operation: return this heuristicCost
     * @return
     */
    double getHeuristicCost() {
        return this->heuristicCost;
    }
};

/**
 * template <class T>
 * @tparam T given T
 */
template<class T>
struct statePHash {
    /**
     * Function name: operator
     * The function operation: performs a hash to a pointer of state,
     * and returns the hash value of the hash function of the point
     * @param state given state
     * @return size_t
     */
    size_t operator()(State<T> *const &state) const {
        return std::hash<T>()(state->getData());
    }
};

/**
 * template <class T>
 * @tparam T given T
 */
template<class T>
struct stateComp {
    /**
     * Function name: operator
     * The function operation: given left and right states, checks the equality
     * of the data of the states
     * @param left given left state
     * @param right given right state
     * @return bool
     */
    bool operator()(State<T> *const &left, State<T> *const &right) const {
        return *(left->getData()) == *(right->getData());
    }
};

#endif
