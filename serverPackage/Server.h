#ifndef SERVER_H
#define SERVER_H

#include "../clientPackage/ClientHandler.h"
//#include "MySerialServer.h"

#include "../solverPackage/Solver.h"
#include "../cachePackage/CacheManager.h"
#include "../cachePackage/FileCacheManager.h"
#include "../solverPackage/StringReverser.h"
#include "../clientPackage/MyTestClientHandler.h"

/**
 * Server class, used to open and run server
 */
namespace server_side {
    class Server {
    public:

        /**
         * Function name: open
         * The function operation: opens a new server by a given port and clientHandler
         * @param port given port
         * @param clientHandler given clientHandler
         */
        virtual void open(int port, ClientHandler &clientHandler) = 0;

        /**
         * Function name: shouldStop
         * The function operation: returns the value of stop
         * @return bool
         */
        virtual bool shouldStop() = 0;

        /**
         * Function name: setStop
         * The function operation: sets the value of stop to false
         */
        virtual void setStop() = 0;

        /**
         * Function name: closeServer
         * The function operation: sets the value of stop to true (to indicate
         * that the server needs to end his work)
         */
        virtual void closeServer() = 0;

        /**
         * Function name: ~Server
         * The function operation: destructs the server
         */
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

#endif
