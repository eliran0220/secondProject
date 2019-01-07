#include "MySerialServer.h"



MySerialServer::MySerialServer() {
    setStop();
}

MySerialServer::~MySerialServer() {
    this->closeServer();
    this->serverThread.join();
}

void MySerialServer::open(int port, ClientHandler& clientHandler) {
    this->serverThread = thread(MySerialServer::runServer, port, &clientHandler, this);
}

void MySerialServer::runServer(int port, ClientHandler *clientHandler, MySerialServer* mySerialServer) {
    while (!mySerialServer->shouldStop()) {
        // create a socket and listen for client
        int sockfd, newsockfd, clilen;
        struct sockaddr_in serv_addr, cli_addr;

        /* First call to socket() function */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        // set timeout 150 s
        struct timeval tv;
        tv.tv_sec = 150;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,(struct timeval *)&tv, sizeof(struct timeval));

        /* Initialize socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(port);

        /* Now bind the host address using bind() call.*/
        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR on binding");
            exit(1);
        }

        /* Now start listening for the clients, here process will
           * go in sleep mode and will wait for the incoming connection
        */

        listen(sockfd, 5);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,
                           (socklen_t *) &clilen);
        if (newsockfd >= 0) {
            clientHandler->handleClient(sockfd);
            close(newsockfd);
        }
    }
}
