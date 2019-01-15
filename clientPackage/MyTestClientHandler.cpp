

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int socket) {
    ssize_t n;
    char buffer[1];
    string clientInput;
    string solutionString;
    // read the first line
    n = read(socket, buffer, 1);
    while (strcmp(buffer, "\n") != 0) {
        clientInput += buffer;
        n = read(socket, buffer, 1);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
    }


    while (clientInput != "end") {
        cout << "Server get: " + clientInput <<endl;
        if (this->cacheManager->isSolutionExist(clientInput)) {
            solutionString = this->cacheManager->popSolution(clientInput);
        } else {
            solutionString = this->solver->solver(clientInput);
            this->cacheManager->saveSolution(clientInput,solutionString);
        }
        n = write(socket, solutionString.c_str(),solutionString.size());
        if(n < 0){
            perror("ERROR writing to socket");
            exit(1);
        }
        clientInput = "";
        n = read(socket, buffer, 1);
        while (strcmp(buffer, "\n") != 0) {
            clientInput += buffer;
            n = read(socket, buffer, 1);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
        }
    }
}

