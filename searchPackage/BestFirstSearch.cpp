//
// Created by eliran on 1/9/19.
//

#include "BestFirstSearch.h"

template<class T, class Solution>
BestFirstSearch<T, Solution>::BestFirstSearch(){
    this->openList = new queue<State <T>>;
    this->evaluatedNodes = 0;
}

template<class T, class Solution>
int BestFirstSearch<T, Solution>::openListSize() {
    return 0;
}

template<class T, class Solution>
State<T> BestFirstSearch<T, Solution>::popOpenList() {
    evaluatedNodes++;

}

