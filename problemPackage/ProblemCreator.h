#ifndef PROBLEMCREATOR_H
#define PROBLEMCREATOR_H

#include <string>

using namespace std;

/**
 * ProblemCreator class, creates a generic problem
 */
template<class P>
class ProblemCreator {
public:

    /**
     * Function name: createProblem
     * The function operation: creates a problem from a given string
     * @param problem given problem
     * @return P
     */
    virtual P createProblem(string problem) = 0;
};

#endif
