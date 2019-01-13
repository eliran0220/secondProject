//
// Created by eliran on 1/12/19.
//

#include <strings.h>
#include <cstring>
#include "MyClientHandler.h"

template <class T>
void MyClientHandler<T>::handleClient(int socket) {
    string clientInput;
    string problemString;
    string solutionString;
    vector<State<T>*> solution;
    clientInput = readFromClient(socket);
    ssize_t n;
    while (clientInput != END) {
        problemString += clientInput;
        problemString += SEPERATOR;
        clientInput = readFromClient(socket);
    }
    if (this->cacheManager->isSolutionExist(problemString)) {
        solutionString = this->cacheManager->popSolution(problemString);
    } else {
        solution = this->solver(this->problemCreator->createProblem(problemString));
        solutionString = this->solver->solutionToString(solution);
        this->cacheManager->saveSolution(problemString, solutionString);
    }
    n = write(socket, solutionString.c_str(),solutionString.size());
    if(n < 0){
        perror("ERROR writing to socket");
        exit(1);
    }
}

template <class  T>
string MyClientHandler<T>::readFromClient(int socket) {
    char buffer[BUFFER_SIZE];
    string clientInput;
    ssize_t n;
    n = read(socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    while (strcmp(buffer, "\n") != 0) {
        clientInput += buffer;
        n = read(socket, buffer, BUFFER_SIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
    }
    return clientInput;
}

