#include "MySerialServer.h"


MySerialServer::MySerialServer() {
    setStop();
}

MySerialServer::~MySerialServer() {
    this->closeServer();
    this->serverThread.join();
}

void MySerialServer::open(int port, ClientHandler &clientHandler) {
    int sockfd = server_side::Server::runServer(port, this);
    this->serverThread = thread(MySerialServer::communicate,this, sockfd, &clientHandler);
}

void MySerialServer::communicate(server_side::Server *server, int sockfd,
                                 ClientHandler *clientHandler) {
    int clilen, newsockfd;
    struct sockaddr_in cli_addr;
    while (!server->shouldStop()) {
        /* Now start listening for the clients, here process will
               * go in sleep mode and will wait for the incoming connection
            */
        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                           (socklen_t *) &clilen);
        if (newsockfd >= 0) {
            clientHandler->handleClient(newsockfd);
            //close(newsockfd);
        }
    }
}


