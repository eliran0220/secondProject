//
// Created by afik on 1/6/19.
//



#include "MySerialServer.h"



MySerialServer::MySerialServer() {
    setStop();
}

MySerialServer::~MySerialServer() {
    this->closeServer();
    this->serverThread.join();
}

void MySerialServer::open(int port, ClientHandler& clientHandler) {
    this->serverThread = thread(MySerialServer::runServer, port, clientHandler, this);
}

void MySerialServer::runServer(int port, ClientHandler &clientHandler, MySerialServer* mySerialServer) {
    while (!mySerialServer->shouldStop()) {
        // create a socket and listen for client

        int sockfd, newsockfd, portno, clilen;
        struct sockaddr_in serv_addr, cli_addr;

        /* First call to socket() function */
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("ERROR opening socket");
            exit(1);
        }

        /* Initialize socket structure */
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = port;

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

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
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }


        ssize_t n;
        char buffer[1];
        string clientInput = "";
        while (clientInput != "end") {
            n = read(newsockfd, buffer, 1);
            while (strcmp(buffer, "\n") != 0) {
                clientInput += buffer;
                n = read(newsockfd, buffer, 1);
                if (n < 0) {
                    perror("ERROR reading from socket");
                    exit(1);
                }
            }
            cout << "Server get: " + clientInput <<endl;
            clientHandler.handleClient(clientInput);
            clientInput = "";
        }
        close(newsockfd);
    }
}
