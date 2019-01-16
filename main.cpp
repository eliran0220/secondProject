#include <iostream>
#include "cachePackage/FileCacheManager.h"
#include "searchPackage/AStar.h"
#include "clientPackage/MyClientHandler.h"
#include "utils/SearchSolver.h"
#include "problemPackage/MatrixProblem.h"
#include "serverPackage/MyParralelServer.h"

#define ERROR_PORT "Missing port number"

/**
 * Funcion name: main
 * The function operation: creates a MyParralelServer,
 * Searcher,Solver, CacheManager,PorblemCreator and clientHandler
 * opens a server, and starts the communication with the client.
 * @param argc given argc
 * @param argv given argv
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc <= 1) {
        cout << ERROR_PORT << endl;
        return 0;
    }
    thread serverThread;
    server_side::Server *server = new MyParralelServer();
    Searcher<Point *> *searcher = new AStar<Point *>();
    Solver<Searchable<Point *> *, vector<State<Point *> *>> *solver =
                                             new SearchSolver<Point *>(searcher);
    CacheManager<string, string> *cacheManager = new FileCacheManager();
    ProblemCreator<Searchable<Point *> *> *problemCreator = new MatrixProblem();
    auto *clientHandler = new MyClientHandler<Point *>(
            solver, cacheManager, problemCreator);
    server->open(atoi(argv[1]), *clientHandler, serverThread);
    serverThread.join();
    delete (server);
    delete (solver);
    delete (searcher);
    delete (problemCreator);
    delete (cacheManager);
    delete (clientHandler);
}




