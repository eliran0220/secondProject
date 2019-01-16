#ifndef SEARCHER_H
#define SEARCHER_H

using namespace std;

#include <queue>
#include <iostream>
#include <algorithm>


#include "State.h"
#include "Searchable.h"
#include "../utils/MyUnorderedSet.h"

/**
 * Searcher class, responsible searching on the Searchable item, and
 * the path to the solution.
 * @param T a given state
 */
template<class T>
class Searcher {
protected:
    int evaluatedNodes;

public:
    /**
     * Function name: ~Searcher
     * The function operation: distructs the Searcher
     */
    virtual ~Searcher() = default;

    /**
     * Function name: search
     * The function operation: performs the search algorithem on the searchable
     * parameter
     * @param searchable given searchable
     * @return vector<State>*>
     */
    virtual vector<State<T> *> search(Searchable<T> *searchable) = 0;

    /**
     * Function name: getNumberOfNodesEvaluated
     * The function operation: returns evaluatedNodes
     * @return int
     */
    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    /**
     * Function name: backTrace
     * The function operation: returns the path backwards from the goal position
     * to the initial position
     * @param state given state
     * @return vector<State>*>
     */
    vector<State<T> *> backTrace(State<T> *state) {
        vector<State<T> *> path;
        State<T> *current = state;
        while (current != nullptr) {
            path.push_back(current);
            current = current->getCameFrom();
        }
        path.reserve(path.size() - 1);

        reverse(path.begin(), path.end());
        return path;
    }

    /**
     * Function name: calculateEvaluatedNodes
     * The function operation: calculates the number of nodes the algorithem
     * has met during the search
     * @param statesInOpenList given UnOrderedSet
     * @param path given vector<State>*>
     * @param closedList given UnOrderedSet
     */
    void calculateEvaluatedNodes(MyUnorderedSet<T> statesInOpenList,
                                 vector<State<T> *> path,
                                 MyUnorderedSet<T> closedList) {
        int temp = 0;
        bool containInSet = false;
        bool containsInOpenList = false;
        MyUnorderedSet<T> tempSet = closedList;
        for (int i = 0; i < (int) path.size(); ++i) {
            if (statesInOpenList.contains(path[i])) {
                containsInOpenList = true;
            }
            if (tempSet.contains(path[i])) {
                containInSet = true;
            }
            if (!containInSet && !containsInOpenList) {
                temp++;
            } else if (containInSet && containsInOpenList) {
                tempSet.remove(path[i]);
            }
            containInSet = false;
            containsInOpenList = false;
        }
        temp += (int) tempSet.size();
        temp += statesInOpenList.size();
        this->evaluatedNodes = temp;
    }

    /**
     * Function name: initialize
     * The function operation: initializes the members of each searcher
     */
    virtual void initialize() = 0;
};

#endif
