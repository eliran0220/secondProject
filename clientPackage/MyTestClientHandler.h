//
// Created by eliran on 1/6/19.
//

#ifndef SECONDPROJECT_MYTESTCLIENTHANDLER_H
#define SECONDPROJECT_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"


class MyTestClientHandler : public ClientHandler {

private:
    class Solver;
    class CacheManager;

public:
    void handleClient(istream input, ostream output);
};


#endif //SECONDPROJECT_MYTESTCLIENTHANDLER_H
