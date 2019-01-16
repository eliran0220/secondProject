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
#define NO_PATH "-1"

/**
 * MyClientHandler class, implements ClientHandler
 * @tparam T a generic State
 */
template<class T>
class MyClientHandler : public ClientHandler {

private:
    CacheManager<string, string> *cacheManager;
    Solver<Searchable<T> *, vector<State<T> *>> *problemSolver;
    ProblemCreator<Searchable<T> *> *problemCreator;

public:
    /**
     * Constructor
     * @param problemSolver
     * @param cacheManager
     * @param problemCreator
     */
    MyClientHandler(
            Solver<Searchable<T> *, vector<State<Point *> *>> *problemSolver,
            CacheManager<string, string> *cacheManager,
            ProblemCreator<Searchable<T> *> *problemCreator) {
        this->problemSolver = problemSolver;
        this->cacheManager = cacheManager;
        this->problemCreator = problemCreator;
    }

    /**
     * handleClient takes care of the client's requests. the client gives an
     * information about the matrix. first he types each row, and in the end he
     * types the initial state and the goal state. lastly, it takes care of it's
     * requests, tries to find a solution, if no solution is found, it creates
     * one, saves it, and forwards it to the client.
     * @param socket
     */
    void handleClient(int socket) override {
        string clientInput;
        string problemString;
        string solutionString;
        vector<State<T> *> solution;
        Searchable<T> *problem;
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
            // if there is no path
            if (solution.empty()) {
                solutionString = NO_PATH;
                this->cacheManager->saveSolution(problemString, solutionString);
            } else {
                solutionString = this->problemSolver->solutionToString(problem,
                                                                      solution);
                this->cacheManager->saveSolution(problemString, solutionString);
            }
        }
        // send the solution
        n = write(socket, solutionString.c_str(), solutionString.size());
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        close(socket);
    }

    /**
     * Function name: readFromClient
     * The function operation: constructs a string from the data given by
     * user each line,
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
