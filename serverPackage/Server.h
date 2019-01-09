//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_SERVER_H
#define SECONDPROJECT_SERVER_H

#include "../clientPackage/ClientHandler.h"
//#include "MySerialServer.h"

#include "../solverPackage/Solver.h"
#include "../cachePackage/CacheManager.h"
#include "../cachePackage/FileCacheManager.h"
#include "../solverPackage/StringReverser.h"
#include "../clientPackage/MyTestClientHandler.h"


namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler &clientHandler) = 0;

        virtual bool shouldStop() = 0;

        virtual void setStop() = 0;

        virtual void closeServer() = 0;

        virtual ~Server() {};


    };
}

/*
namespace boot {
#include "MySerialServer.h"
    class Main {
    public:
        int main(int argc, char *argv[]) {
            MySerialServer *server = new MySerialServer();
            Solver<string, string> *solver = new StringReverser();
            CacheManager<string, string> *cacheManager = new FileCacheManager(
                    "a.txt");
            ClientHandler *clientHandler = new MyTestClientHandler(solver,
                                                                   cacheManager);
            server->open(atoi(argv[1]), *clientHandler);
            sleep(20);
            delete (server);
            delete (solver);
            delete (cacheManager);
            delete (clientHandler);
        }
    };
}
 */

#endif //SECONDPROJECT_SERVER_H
