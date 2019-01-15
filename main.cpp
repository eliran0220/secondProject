#include <iostream>
#include "cachePackage/FileCacheManager.h"
#include "searchPackage/AStar.h"
#include "clientPackage/MyClientHandler.h"
#include "utils/SearchSolver.h"
#include "problemPackage/MatrixProblem.h"
#include "serverPackage/MyParralelServer.h"


int main(int argc, char *argv[]) {
    server_side::Server *server = new MyParralelServer();
    Searcher<Point *> *searcher = new AStar<Point *>();
    Solver<Searchable<Point *> *, vector<State<Point *> *>> *solver = new SearchSolver<Point *>(
            searcher);
    CacheManager<string, string> *cacheManager = new FileCacheManager(argv[2]);
    ProblemCreator<Searchable<Point *> *> *problemCreator = new MatrixProblem();
    auto *clientHandler = new MyClientHandler<Point *>(
            solver, cacheManager, problemCreator);
    server->open(atoi(argv[1]), *clientHandler);
    delete (server);
    delete (solver);
    delete (searcher);
    delete(problemCreator);
    delete (cacheManager);
    delete (clientHandler);
}




