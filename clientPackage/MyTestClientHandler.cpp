
#include "MyTestClientHandler.h"

template <class P, class S>
void MyTestClientHandler<P,S>::handleClient(int socket) {
    ssize_t n;
    char buffer[1];
    string clientInput = "";
    P problem;
    S solution;
    string solutionString;
    while (clientInput != "end") {
        n = read(socket, buffer, 1);
        while (strcmp(buffer, "\n") != 0) {
            clientInput += buffer;
            n = read(socket, buffer, 1);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
        }
        cout << "Server get: " + clientInput <<endl;
        if (this->cacheManager->isSolutionExist(clientInput)) {
            solutionString = this->cacheManager->popSolution(clientInput);
        } else {
            problem = this->solver->stringToProblem(clientInput);
            solution = this->solver->solver(problem);
            solutionString = this->solver->solutionToString(solution);
        }
        n = write(socket, solutionString.c_str(),solutionString.size());
        if(n < 0){
            perror("ERROR writing to socket");
            exit(1);
        }
        clientInput = "";
    }
}

