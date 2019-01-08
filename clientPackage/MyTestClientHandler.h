//
#ifndef SECONDPROJECT_MYTESTCLIENTHANDLER_H
#define SECONDPROJECT_MYTESTCLIENTHANDLER_H


#include <cstring>
#include <iostream>

#include "ClientHandler.h"
#include "../solverPackage/Solver.h"
#include "../solverPackage/StringReverser.h"
#include "../cachePackage/CacheManager.h"


class MyTestClientHandler : public ClientHandler {

private:
    CacheManager<string, string>* cacheManager;
    Solver<string, string>* solver;

public:
    MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cacheManager) {
        this->solver = solver;
        this->cacheManager = cacheManager;
    }
    void handleClient(int socket) override;
};


#endif
