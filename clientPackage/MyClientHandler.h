//
// Created by eliran on 1/12/19.
//

#ifndef SECONDPROJECT_MYCLIENTHANDLER_H
#define SECONDPROJECT_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "../cachePackage/CacheManager.h"
#include "../solverPackage/Solver.h"
#include "../searchPackage/Searchable.h"
#include "../problemPackage/ProblemCreator.h"

#define END "end"
#define BUFFER_SIZE 1
#define SEPERATOR "$"

template <class T>
class MyClientHandler : public ClientHandler {

private:
    CacheManager<string, string>* cacheManager;
    Solver<Searchable<T>*, vector<State<T>*>>* solver;
    ProblemCreator<Searchable<T>*>* problemCreator;

public:
    MyClientHandler(Solver<Searchable<T>*, string> *solver, CacheManager<string, string> *cacheManager,ProblemCreator<Searchable<T>*>* problemCreator) {
        this->solver = solver;
        this->cacheManager = cacheManager;
        this->problemCreator = problemCreator;
    }
    void handleClient(int socket) override;
    string readFromClient(int socket);
};


#endif //SECONDPROJECT_MYCLIENTHANDLER_H
