//
// Created by eliran on 1/6/19.
//

#include <algorithm>
#include "StringReverser.h"

template<class P, class S>
string StringReverser<P, S>::solver(string problem) {
    string solution = problem;
    reverse(solution.begin(), solution.end());
    return solution;
}