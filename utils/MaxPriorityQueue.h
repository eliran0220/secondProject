//
// Created by afik on 1/10/19.
//

#ifndef SECONDPROJECT_MAXPRIORITYQUEUE_H
#define SECONDPROJECT_MAXPRIORITYQUEUE_H


#include <queue>
#include "MyPriorityQueue.h"

using namespace std;

template <class T>
struct compare
{
    bool operator()(State<T>* l, State<T>* r)
    {
        return l->getCost() < r->getCost();
    }
};

template <class T>
class MaxPriorityQueue : public MyPriorityQueue<T> {

    priority_queue<State<T>*,vector<State<T>*>,compare<T>> priorityQueue;
    int sizeQueue;
    set<State<T>*> setOfStates;

public:
    MaxPriorityQueue(){
        this->sizeQueue= 0;
    }


    void push(State<T>* state) {
        priorityQueue.push(state);
        this->setOfStates.insert(state);
        this->sizeQueue++;
    }

    int size() {
        return this->sizeQueue;
    }

    State<T>* poll() {
        if (this->sizeQueue > 0) {
            State<T>* state = priorityQueue.top();
            priorityQueue.pop();
            this->setOfStates.erase(state);
            this->sizeQueue--;
            return state;
        }
        return nullptr;
    }

    bool isEmpty() {
        if (this->sizeQueue == 0) {
            return true;
        }
        return false;
    }

    bool contains(State<T>* state) {
        if (this->setOfStates.count(state) == 1) {
            return true;
        }
        return false;
    }
};

#endif //SECONDPROJECT_MAXPRIORITYQUEUE_H
