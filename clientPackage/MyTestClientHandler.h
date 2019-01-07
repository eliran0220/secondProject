//
#ifndef SECONDPROJECT_MYTESTCLIENTHANDLER_H
#define SECONDPROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "../solverPackage/Solver.h"
#include "../solverPackage/StringReverser.h"
#include "../cachePackage/CacheManager.h"


template <class P, class S>
class MyTestClientHandler : public ClientHandler {

private:
    CacheManager<P,S>* cacheManager;
    Solver<P, S>* solver;

public:
    MyTestClientHandler(Solver<P,S> &solver, CacheManager<P,S> &cacheManager) {
        this->solver = solver;
        this->cacheManager = cacheManager;
    }
    void handleClient(string input);
};


#endif
