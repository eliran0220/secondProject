//
// Created by eliran on 1/8/19.
//

#ifndef SECONDPROJECT_SEARCHER_H
#define SECONDPROJECT_SEARCHER_H

using namespace std;

#include <queue>
#include <iostream>


#include "State.h"
#include "Searchable.h"
#include "../utils/MyUnorderedSet.h"


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

    void calculateEvaluatedNodes(MyUnorderedSet<T> statesInOpenList, vector<State<T> *> path,
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
};

#endif //SECONDPROJECT_SEARCHER_H
