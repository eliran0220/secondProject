#ifndef SECONDPROJECT_MYPRIORITYSTACK_H
#define SECONDPROJECT_MYPRIORITYSTACK_H

#include "stack"
#include "MyPriority.h"

template <class T>
class MyPriorityStack : public MyPriority<T>{
    stack<State<T>*> myStack;
    int sizeStack;
    set<State<T>*> setOfStates;


public:
    MyPriorityStack(){
        this->sizeStack = 0;
    }

    void push(State<T>* state) {
        myStack.push(state);
        this->setOfStates.insert(state);
        sizeStack++;
    }

    int size() {
        return this->sizeStack;
    }

    State<T>* poll() {
        if (this->sizeStack > 0) {
            State<T>* state = myStack.top();
            myStack.pop();
            this->setOfStates.erase(state);
            this->sizeStack--;
            return state;
        }
    }

    bool isEmpty() {
        return this->sizeStack == 0;
    }

    bool contains(State<T>* state) {
        if (this->setOfStates.count(state) == 1) {
            return true;
        }
        return false;
    }

    void eraseAndPush(State<T>* state) {
    }


};
#endif //SECONDPROJECT_MYPRIORITYSTACK_H
