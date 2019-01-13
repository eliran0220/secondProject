//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_STRINGREVERSER_H
#define SECONDPROJECT_STRINGREVERSER_H

#include "Solver.h"

class StringReverser : public Solver<string,string>{

public:
    StringReverser() {}
    string solver(string problem) override;
    string solutionToString(string solution) override;
};

#endif //SECONDPROJECT_STRINGREVERSER_H
