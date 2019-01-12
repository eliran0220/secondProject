//
// Created by eliran on 1/12/19.
//

#ifndef SECONDPROJECT_PROBLEMCREATOR_H
#define SECONDPROJECT_PROBLEMCREATOR_H

#include <string.h>

template<class P>
class ProblemCreator {
    virtual P createProblem(string problem) = 0;

};

#endif //SECONDPROJECT_PROBLEMCREATOR_H
