//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_SERVER_H
#define SECONDPROJECT_SERVER_H

#include "../clientPackage/ClientHandler.h"


namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler &clientHandler) = 0;

        virtual bool shouldStop() = 0;

        virtual void setStop() = 0;

        virtual void closeServer() = 0;

        virtual ~Server(){};


    };
}

/*
namespace boot {
#include "MySerialServer.h"
#include "../clientPackage/ClientHandler.h"
#include "../solverPackage/Solver.h"
#include "../cachePackage/CacheManager.h"
#include "../cachePackage/FileCacheManager.h"
#include "../solverPackage/StringReverser.h"

    class Main {
    public:
        int main(int argc, char *argv[]) {
            server_side::Server server = new  MySerialServer();
            Solver<string, string> solver = StringReverser();
            CacheManager<string, string> cacheManager = FileCacheManager("a.txt", "b.txt");
            ClientHandler<string, string> clientHandler = MyTestClientHandler(solver, cacheManager);
            server.open(argv[1],clientHandler);
            sleep(500);
        }
    };
}
 */
#endif //SECONDPROJECT_SERVER_H
