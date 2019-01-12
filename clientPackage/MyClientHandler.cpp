//
// Created by eliran on 1/12/19.
//

#include <strings.h>
#include <cstring>
#include "MyClientHandler.h"

void MyClientHandler::handleClient(int socket) {
    string clientInput = "";
    string problem;
    string solutionString ="";
    clientInput = readFromClient(socket);
    while (clientInput != END) {
        problem += clientInput;
        problem += SEPERATOR;
        clientInput = readFromClient(socket);
    }

    if (this->cacheManager->isSolutionExist(problem)){
        solutionString += this->cacheManager->popSolution(problem);
    } else {
        //create a new problem

    }

}

string MyClientHandler::readFromClient(int socket){
    char buffer[BUFFER_SIZE];
    ssize_t n;
    n = read(socket,buffer,BUFFER_SIZE-1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    return string(buffer);
}

