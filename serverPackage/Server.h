#ifndef SERVER_H
#define SERVER_H

#include "../clientPackage/ClientHandler.h"

#include <netinet/in.h>
#include <strings.h>
#include <thread>
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
         * The function operation: opens a new server by a given port and
         * clientHandler
         * @param port given port
         * @param clientHandler given clientHandler
         */
        virtual void
        open(int port, ClientHandler &clientHandler, thread &serverThread) = 0;

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
        static int createSocket(int port, server_side::Server *mySerialServer) {
            int sockfd;
            struct sockaddr_in serv_addr;
            if (!mySerialServer->shouldStop()) {
                /* First call to socket() function */
                sockfd = socket(AF_INET, SOCK_STREAM, 0);

                if (sockfd < 0) {
                    perror("ERROR opening socket");
                    exit(1);
                }
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
         * Function name : settimeout;
         * The function operation: sets the timeout for given socket.
         * @param sec given second
         * @param usec
         * @param socket
         */
        static void settimeout(int sec, int usec, int socket) {
            timeval timeout;
            timeout.tv_sec = sec;
            timeout.tv_usec = usec;
            // setting socket option for recieve timeout
            if (setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO,
                           (char *) &timeout, sizeof(timeout)) == -1) {
                throw std::system_error(
                        std::error_code(errno, std::generic_category()),
                        "failure on setsockopt");
            }
        }

        /**
         * Function name: ~Server
         * The function operation: destructs the server
         */
        virtual ~Server() = default;

    };
}

#endif
