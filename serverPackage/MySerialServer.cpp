#include "MySerialServer.h"


MySerialServer::MySerialServer() {
    setStop();
}

MySerialServer::~MySerialServer() {
    this->closeServer();
    this->serverThread.join();
}

void MySerialServer::open(int port, ClientHandler &clientHandler, thread& serverThread) {
    int sockfd = server_side::Server::createSocket(port, this);
    this->serverThread = thread(MySerialServer::communicate,this, sockfd, &clientHandler);
}


void MySerialServer::communicate(server_side::Server *server, int sockfd,
                                 ClientHandler *clientHandler) {
    int clilen, newsockfd;
    struct sockaddr_in cli_addr;
    clilen = sizeof(cli_addr);
    listen(sockfd, 5);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                       (socklen_t *) &clilen);
    if (newsockfd >= 0) {
        server_side::Server::settimeout(0,0,newsockfd);
        clientHandler->handleClient(newsockfd);
    }
    server_side::Server::settimeout(1,0,sockfd);
    while (!server->shouldStop()) {
        /* Now start listening for the clients, here process will
         * go in sleep mode and will wait for the incoming connection
         */
        if (newsockfd >= 0) {
            server_side::Server::settimeout(0,0,newsockfd);
            clientHandler->handleClient(newsockfd);
        }
    }
    close(sockfd);
}


