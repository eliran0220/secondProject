#include <algorithm>
#include "StringReverser.h"

string StringReverser::solver(string problem) {
    string solution = problem;
    reverse(solution.begin(), solution.end());
    return solution;
}


string StringReverser::solutionToString(string problem, string solution) {
    return solution;
}

