#include "MyParralelServer.h"


MyParralelServer::MyParralelServer() {
    setStop();
}

MyParralelServer::~MyParralelServer() {
    this->closeServer();
    for (thread &th : this->serverThreads) {
        th.join();
    }
}

void MyParralelServer::open(int port, ClientHandler &clientHandler,
                            thread &serverThread) {
    int sockfd = server_side::Server::createSocket(port, this);
    serverThread = thread(MyParralelServer::openMainServerThread, sockfd,
                          &clientHandler, this);
}

void MyParralelServer::openMainServerThread(int sockfd,
                                            ClientHandler *clientHandler,
                                            MyParralelServer *server) {
    int clilen, newsockfd;
    struct sockaddr_in cli_addr;

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    // accept the first client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                       (socklen_t *) &clilen);

    if (newsockfd >= 0) {
        server_side::Server::settimeout(0, 0, newsockfd);
        server->serverThreads.emplace_back(
                thread(MyParralelServer::communicate, newsockfd,
                       clientHandler));
    }
    // set the time-out to 1.
    server_side::Server::settimeout(1, 0, sockfd);
    while (true) {
        /* Now start listening for the clients, here process will
         * go in sleep mode and will wait for the incoming connection
         */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                           (socklen_t *) &clilen);


        if (newsockfd >= 0) {
            server_side::Server::settimeout(0, 0, newsockfd);
            server->serverThreads.emplace_back(
                    thread(MyParralelServer::communicate, newsockfd,
                           clientHandler));
            // if the time-out finish break the loop.
        } else {
            break;
        }
    }
    close(sockfd);
}

void MyParralelServer::communicate(int sockfd, ClientHandler *clientHandler) {
    clientHandler->handleClient(sockfd);
}



