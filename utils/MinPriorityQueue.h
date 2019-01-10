//
// Created by afik on 1/9/19.
//

#ifndef SECONDPROJECT_MINPRIORITYQUEUE_H
#define SECONDPROJECT_MINPRIORITYQUEUE_H


#include <queue>
#include <set>
#include "MyPriorityQueue.h"

using namespace std;

template <class T>
struct compare
{
    bool operator()(State<T>* l, State<T>* r)
    {
        return l->getCost() > r->getCost();
    }
};

template <class T>
class MinPriorityQueue : public MyPriorityQueue<T> {

    priority_queue<State<T>*,vector<State<T>*>,compare<T>> priorityQueue;
    int sizeQueue;
    set<State<T>*> setOfStates;

public:
    MinPriorityQueue(){
        this->sizeQueue= 0;
       //this->priorityQueue = priority_queue<State<T>*,vector<State<T>>,compare<T>>;
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

    void eraseAndPush(State<T>* state) {
        vector<State<T>*> states;
        State<T>* temp;
        temp = this->poll();
        while (temp != nullptr) {
            if (!state->Equals(temp)) {
                states.push_back(temp);
            } else {
                break;
            }
        }
        for (int i = 0; i < (int)states.size(); ++i) {
            this->push(states[i]);
        }
    }
};


#endif //SECONDPROJECT_MINPRIORITYQUEUE_H
