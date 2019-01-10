//
// Created by afik on 1/9/19.
//

#ifndef SECONDPROJECT_MYPRIORITYQUEUE_H
#define SECONDPROJECT_MYPRIORITYQUEUE_H

#include <set>
#include <queue>

#include "../searchPackage/State.h"
using namespace std;


template <class T>
class MyPriorityQueue{
    /*
protected:
    priority_queue<State<T>*> priorityQueue;
    int sizeQueue;
    set<State<T>*> setOfStates;

public:
    MyPriorityQueue(){
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
            //return priorityQueue.pop();
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
     */
public:
    virtual void push(State<T>* state) = 0;
    virtual int size() = 0;
    //virtual bool contains(State<T>& state) = 0;
    virtual State<T>* poll() = 0;
    virtual bool isEmpty() = 0 ;
    virtual bool contains(State<T>* state) = 0;

    virtual void eraseAndPush(State<T>* state) = 0;
};
#endif //SECONDPROJECT_MYPRIORITYQUEUE_H
