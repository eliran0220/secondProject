//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_MYTESTCLIENTHANDLER_H
#define SECONDPROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "../solverPackage/Solver.h"

class MyTestClientHandler : ClientHandler {

private:
    class Solver;

public:
    void handleClient(istream input, ostream output);
};


#endif //SECONDPROJECT_MYTESTCLIENTHANDLER_H
