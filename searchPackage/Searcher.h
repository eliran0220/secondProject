//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHER_H
#define SECONDPROJECT_SEARCHER_H

using namespace std;

#include <queue>
#include <iostream>
#include <set>
#include "State.h"
#include "Searchable.h"

template<class T>
class Searcher {
protected:
    int evaluatedNodes;

public:
    virtual vector<State<T>*> search(Searchable<T>* searchable) = 0;

    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    vector<State<T>*> backTrace(State<T>* state) {
        vector<State<T>*> path;
        State<T>* current = state;
        while (current != nullptr) {
            path.push_back(current);
            current = current->getCameFrom();
        }
        return path;
    }

    void calculateEvaluatedNodes(set<State<T>*> statesInOpenList, vector<State<T> *> path,
                                 set<State<T> *> closedList) {
        int temp = 0;
        bool containInSet = false;
        bool containsInOpenList = false;
        set<State<T> *> tempSet = closedList;
        for (int i = 0; i < (int) path.size(); ++i) {
            if (statesInOpenList.count(path[i]) >= 1) {
                containsInOpenList = true;
            }
            if (tempSet.count(path[i]) >= 1) {
                containInSet = true;
            }
            if (!containInSet && !containsInOpenList) {
                temp++;
            } else if (containInSet && containsInOpenList) {
                tempSet.erase(path[i]);
            }
            containInSet = false;
            containsInOpenList = false;
        }
        temp += (int) tempSet.size();
        temp += statesInOpenList.size();
        this->evaluatedNodes = temp;
    }
};

#endif //SECONDPROJECT_SEARCHER_H
