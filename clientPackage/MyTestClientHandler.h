#ifndef MYTESTCLIENTHANDLER_H
#define MYTESTCLIENTHANDLER_H

#include <cstring>
#include <iostream>

#include "ClientHandler.h"
#include "../solverPackage/Solver.h"
#include "../solverPackage/StringReverser.h"
#include "../cachePackage/CacheManager.h"

/**
 * MyTestClientHandler class.
 */
class MyTestClientHandler : public ClientHandler {

private:
    CacheManager<string, string> *cacheManager;
    Solver<string, string> *solver;

public:
    /**
     * Constructor
     * @param solver
     * @param cacheManager
     */
    MyTestClientHandler(Solver<string, string> *solver,
                        CacheManager<string, string> *cacheManager) {
        this->solver = solver;
        this->cacheManager = cacheManager;
    }

    /**
     * handleClient takes care of the client's requests. the client gives an
     * information about the matrix. first he types each row, and in the end he
     * types the initial state and the goal state. lastly, it takes care of it's
     * requests, tries to find a solution, if no solution is found, it creates
     * one, saves it, and forwards it to the client.
     * @param socket
     */
    void handleClient(int socket) override;
};

#endif