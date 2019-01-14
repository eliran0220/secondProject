#ifndef MYCLIENTHANDLER_H
#define MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "../cachePackage/CacheManager.h"
#include "../solverPackage/Solver.h"
#include "../searchPackage/Searchable.h"
#include "../problemPackage/ProblemCreator.h"
#include <strings.h>
#include <cstring>
#include <mutex>

#define END "end"
#define BUFFER_SIZE 1
#define SEPERATOR ":"


/**
 * MyClientHandler class, implements ClientHandler
 * @tparam T a generic State
 */
template <class T>
class MyClientHandler : public ClientHandler {

private:
    CacheManager<string, string>* cacheManager;
    Solver<Searchable<T>*, vector<State<T>*>>* problemSolver;
    ProblemCreator<Searchable<T>*>* problemCreator;

public:

    MyClientHandler(Solver<Searchable<T>*,  vector<State<Point*>*>> *problemSolver, CacheManager<string, string> *cacheManager,ProblemCreator<Searchable<T>*>* problemCreator) {
        this->problemSolver = problemSolver;
        this->cacheManager = cacheManager;
        this->problemCreator = problemCreator;
    }


    void handleClient(int socket) override {
        string clientInput;
        string problemString;
        string solutionString;
        vector<State<T>*> solution;
        Searchable<T>* problem;
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
            problem = this->problemCreator->createProblem(problemString);
            solution = this->problemSolver->solver(problem);
            if (solution.empty()) {
                solutionString = "-1";
                this->cacheManager->saveSolution(problemString, solutionString);
            } else {
                solutionString = this->problemSolver->solutionToString(problem, solution);
                this->cacheManager->saveSolution(problemString, solutionString);
            }
        }
        n = write(socket, solutionString.c_str(),solutionString.size());
        if(n < 0){
            perror("ERROR writing to socket");
            exit(1);
        }
        close(socket);
    }

    /**
     * Function name: readFromClient
     * The function operation: constructs a string from the data given by user each line,
     * and returns it
     * @param socket a given socket
     * @return string
     */
    string readFromClient(int socket) {
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
};


#endif
