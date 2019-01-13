#ifndef SOLVER_H
#define SOLVER_H

#include <string>

using namespace std;

/**
 * Solver class, used to solve a problem and convert solution to string
 * @tparam P given problem
 * @tparam S solution
 */
template<class P, class S>
class Solver {
public:

    /**
     * Function name: solver
     * The function operation: given a problem, it solves it and returns a solution
     * @param problem a given problem
     * @return S solution
     */
    virtual S solver(P problem) = 0;

    /**
     * Function name: solutionToString
     * The function operation: given a solution, covnerts it to string and returns it
     * @param solution given solution
     * @return string
     */
    virtual string solutionToString(S solution) = 0;

    /**
     * Function name: ~Solver
     * The function operation: distructs the solver
     */
    virtual ~Solver() = default;
};

#endif