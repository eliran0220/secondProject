//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_SOLVER_H
#define SECONDPROJECT_SOLVER_H

template <class P, class S>  class Solver {

public:
    virtual S solver(P problem) = 0;
};

#endif //SECONDPROJECT_SOLVER_H
