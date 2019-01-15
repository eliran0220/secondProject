//
// Created by eliran on 1/14/19.
//

#ifndef SECONDPROJECT_MAINBOOT_H
#define SECONDPROJECT_MAINBOOT_H

#include "MySerialServer.h"
#include "../cachePackage/FileCacheManager.h"
#include "../searchPackage/AStar.h"
#include "../clientPackage/MyClientHandler.h"
#include "../utils/SearchSolver.h"
#include "../problemPackage/MatrixProblem.h"


#define ERROR "Missing port number"

namespace server_side {
    namespace boot {
        class Main;
    }
}

class server_side::boot::Main {
public:
    int main(int argc, char *argv[]) {
            if ( argc <= 1)  {
                    cout << ERROR << endl;
                    return 0;
            }
            thread serverThread;
            server_side::Server *server = new MySerialServer();
            Searcher<Point *> *searcher = new AStar<Point *>();
            Solver<Searchable<Point *> *, vector<State<Point *> *>> *solver = new SearchSolver<Point *>(
                    searcher);
            CacheManager<string, string> *cacheManager = new FileCacheManager();
            ProblemCreator<Searchable<Point *> *> *problemCreator = new MatrixProblem();
            auto *clientHandler = new MyClientHandler<Point *>(
                    solver, cacheManager, problemCreator);
            server->open(atoi(argv[1]), *clientHandler, serverThread);
            serverThread.join();
            delete (server);
            delete (solver);
            delete (searcher);
            delete(problemCreator);
            delete (cacheManager);
            delete (clientHandler);
    }
};

#endif
