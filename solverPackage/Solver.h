//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_SOLVER_H
#define SECONDPROJECT_SOLVER_H

#include <string>

using namespace std;

template<class P, class S>
class Solver {
public:
    virtual S solver(P problem) = 0;
    virtual string solutionToString(S solution) = 0;
    virtual ~Solver() = default;
};

#endif //SECONDPROJECT_SOLVER_H
