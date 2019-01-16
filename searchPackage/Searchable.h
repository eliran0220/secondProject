#ifndef SEARCHABLE_H
#define SEARCHABLE_H

using namespace std;

#include <list>
#include <vector>
#include "State.h"

using std::string;

template<class T>
class Searchable {
public:
    /**
     * Function name: getInitialState
     * The function operation: returns the initial state
     * @return State<T>*
     */
    virtual State<T> *getInitialState() = 0;

    /**
     * Function nname: getGoalState
     * The function oepration: returns the goal state
     * @return State<T>*
     */
    virtual State<T> *getGoalState() = 0;

    /**
     * Function name: getAllPossibleStates
     * The function operation: the function returns all the possible states
     * that could be the neighbors of the given state
     * @param state given state
     * @return vector<vector<Point *> *>
     */
    virtual vector<State<T> *> getAllPossibleStates(State<T> *state) = 0;

    /**
     * Function name: pathToString
     * The function operation: given a path, it converts it to a string
     * @param path given path
     * @return string
     */
    virtual string pathToString(vector<State<T> *> path) = 0;

    /**
     * Function name: ~Searchable
     * The function operation: destructor
     */
    virtual ~Searchable() = default;

};

#endif
