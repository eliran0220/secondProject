#ifndef STRINGREVERSER_H
#define STRINGREVERSER_H

#include "Solver.h"

/**
 * StringReverser class, implements the Solver
 */
class StringReverser : public Solver<string, string> {

public:
    /**
     * Function name: StringReverser
     * The function operation: constructs a new StringReverser
     */
    StringReverser() {}

    /**
     * Function name: solver
     * The function operation: given a problem which is a string, the function reverses the
     * string
     * @param problem given problem
     * @return string
     */
    string solver(string problem) override;

    /**
     * Function name: solutionToString
     * The function operation: given a solution we convert it to string
     * @param solution given solution
     * @return string
     */
    string solutionToString(string problem, string solution) override;
};

#endif
