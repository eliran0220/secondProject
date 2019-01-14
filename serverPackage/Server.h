#ifndef SERVER_H
#define SERVER_H

#include "../clientPackage/ClientHandler.h"
//#include "MySerialServer.h"

#include <netinet/in.h>
#include <strings.h>
#include <pthread.h>
#include <cstring>
#include <iostream>
#include <unistd.h>

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
         * Function name: runServer
         * The function operation: runs the server
         * @param port given port
         * @param clientHandler given clientHandler
         * @param mySerialServer given MySerialServer
        */
        static int runServer(int port, server_side::Server *mySerialServer) {
                int sockfd;
                struct sockaddr_in serv_addr;
                if (!mySerialServer->shouldStop()) {
                        /* First call to socket() function */
                        sockfd = socket(AF_INET, SOCK_STREAM, 0);

                        if (sockfd < 0) {
                                perror("ERROR opening socket");
                                exit(1);
                        }

                        // set timeout 100 s
                        struct timeval tv;
                        tv.tv_sec = 100;
                        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,
                                   (struct timeval *) &tv,
                                   sizeof(struct timeval));

                        /* Initialize socket structure */
                        bzero((char *) &serv_addr, sizeof(serv_addr));

                        // create a socket and listen for client
                        serv_addr.sin_family = AF_INET;
                        serv_addr.sin_addr.s_addr = INADDR_ANY;
                        serv_addr.sin_port = htons(port);

                        /* Now bind the host address using bind() call.*/
                        if (bind(sockfd, (struct sockaddr *) &serv_addr,
                                 sizeof(serv_addr)) <
                            0) {
                                perror("ERROR on binding");
                                exit(1);
                        }
                }
                return sockfd;
        }
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
