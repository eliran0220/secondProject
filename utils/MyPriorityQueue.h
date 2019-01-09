//
// Created by afik on 1/9/19.
//

#ifndef SECONDPROJECT_MYPRIORITYQUEUE_H
#define SECONDPROJECT_MYPRIORITYQUEUE_H

#include "../searchPackage/State.h"

class MyPriorityQueue{
    virtual void push(State<T>& state) = 0;
    virtual int size() = 0;
    //virtual bool contains(State<T>& state) = 0;
    virtual State<T>& poll() = 0;
    virtual bool isEmpty() = 0 ;
};
#endif //SECONDPROJECT_MYPRIORITYQUEUE_H
