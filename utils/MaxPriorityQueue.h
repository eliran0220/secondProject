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
    bool operator()(const State<T>& l, const State<T>& r)
    {
        return l.getCost() > r.getCost();
    }
};

template <class T>
class MaxPriorityQueue : public MyPriorityQueue {

    priority_queue<State<T>,vector<State<T>>,compare<T>> priorityQueue;
    int sizeQueue;

public:
    MaxPriorityQueue(){
        this->sizeQueue= 0;
    }

    void push(State<T>& state) {
        priorityQueue.push(state);
        this->sizeQueue++;
    }

    int size() {
        return this->sizeQueue;
    }

    State<T>& poll() {
        if (this->sizeQueue > 0) {
            return priorityQueue.pop();
            this->sizeQueue--;
        }
        return nullptr;
    }

    bool isEmpty() {
        if (this->sizeQueue == 0) {
            return true;
        }
        return false;
    }
};

#endif //SECONDPROJECT_MAXPRIORITYQUEUE_H
