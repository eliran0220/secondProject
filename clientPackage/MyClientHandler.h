//
// Created by eliran on 1/12/19.
//

#ifndef SECONDPROJECT_MYCLIENTHANDLER_H
#define SECONDPROJECT_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "../cachePackage/CacheManager.h"
#include "../solverPackage/Solver.h"

class MyClientHandler : public ClientHandler {

private:
    CacheManager<string, string>* cacheManager;
    Solver<string, string>* solver;
public:
    MyClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cacheManager) {
        this->solver = solver;
        this->cacheManager = cacheManager;
    }
    void handleClient(int socket) override;
    string readFromClient(int socket);
};


#endif //SECONDPROJECT_MYCLIENTHANDLER_H
