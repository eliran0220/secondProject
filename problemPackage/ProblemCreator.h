//
// Created by eliran on 1/12/19.
//

#ifndef SECONDPROJECT_PROBLEMCREATOR_H
#define SECONDPROJECT_PROBLEMCREATOR_H

#include <string>

using namespace std;

template<class P>
class ProblemCreator {
public:
    virtual P createProblem(string problem) = 0;
};

#endif //SECONDPROJECT_PROBLEMCREATOR_H
