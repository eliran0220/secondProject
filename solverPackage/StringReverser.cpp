    //
// Created by eliran on 1/6/19.
//

#include <algorithm>
#include "StringReverser.h"

string StringReverser::solver(string problem) {
    string solution = problem;
    reverse(solution.begin(), solution.end());
    return solution;
}


string StringReverser::solutionToString(string solution) {
    return solution;
}

string StringReverser::stringToProblem(string problemString) {
    return problemString;
}