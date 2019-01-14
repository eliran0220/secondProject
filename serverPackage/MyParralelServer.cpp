#include "MyParralelServer.h"


MyParralelServer::MyParralelServer() {
    setStop();
}

MyParralelServer::~MyParralelServer() {
    this->closeServer();
    for (thread & th : this->serverThreads) {
        th.join();
    }
}

void MyParralelServer::open(int port, ClientHandler &clientHandler) {
    //this->serverThreads.emplace_back(thread(MyParralelServer::openMainServerThread, port, clientHandler,this));
    //MyParralelServer::openMainServerThread(port, clientHandler, this);
    int sockfd = server_side::Server::runServer(port, this);
    this->serverThreads.emplace_back(thread(MyParralelServer::openMainServerThread, sockfd, &clientHandler,this));
    //thread(MyParralelServer::openMainServerThread, sockfd, &clientHandler,this);
}

void MyParralelServer::openMainServerThread(int sockfd,
                                            ClientHandler *clientHandler,
                                            MyParralelServer* server) {
    int clilen, newsockfd;
    struct sockaddr_in cli_addr;
    server_side::Server::settimeout(0,2,sockfd);
    while (!server->shouldStop()) {
        /* Now start listening for the clients, here process will
               * go in sleep mode and will wait for the incoming connection
            */
        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                           (socklen_t *) &clilen);

        server_side::Server::settimeout(0,0,newsockfd);
        if (newsockfd >= 0) {
            server->serverThreads.emplace_back(thread(MyParralelServer::communicate,newsockfd, clientHandler));
            //thread(MyParralelServer::communicate,newsockfd, &clientHandler);
        }
    }
    close(sockfd);
}

void MyParralelServer::communicate(int sockfd, ClientHandler *clientHandler) {
    clientHandler->handleClient(sockfd);
}



