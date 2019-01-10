//
// Created by eliran on 1/9/19.
//


#include "BestFirstSearch.h"

template<class T, class Solution>
BestFirstSearch<T, Solution>::BestFirstSearch() {
    this->openList = new queue<State<T>>;
    this->evaluatedNodes = 0;
}

template<class T, class Solution>
int BestFirstSearch<T, Solution>::openListSize() {
    openList.size(); // צריך לשנות לפריוריטי קיו האמיתי עם הפונקציה size
}

template<class T, class Solution>
State<T> BestFirstSearch<T, Solution>::popOpenList() {
    evaluatedNodes++;
    return openList.poll();
}
/*
template<class T, class Solution>
Solution BestFirstSearch<T, Solution>::search(Searchable<T> searchable) {
    this->openList.push(searchable.getInitialState()); // push the initial state
    set<State<T>> closed = new set<State<T>>;
    while (this->openList.size() > 0) {
        State<T> n = popOpenList();
        closed.insert(n);
        if (n.Equals(searchable.getGoalState()))
            return backTrace();
        list<State<T>> successors = searchable.getAllPossibleStates();
        for (State<T> state : successors) {
            if (!closed.find(state)) {
                openList.push(state);
            } else  {

            }
        }
    }
}
 */



