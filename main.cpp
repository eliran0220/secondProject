#include <iostream>
#include "cachePackage/FileCacheManager.h"
#include "searchPackage/AStar.h"
#include "clientPackage/MyClientHandler.h"
#include "utils/SearchSolver.h"
#include "problemPackage/MatrixProblem.h"
#include "serverPackage/MyParralelServer.h"
#include "serverPackage/MainBoot.h"

#define ERROR_PORT "Missing port number"

int main(int argc, char *argv[]) {

    if ( argc <= 1)  {
        cout << ERROR << endl;
        return 0;
    }
    thread serverThread;
    server_side::Server *server = new MySerialServer();
    Solver<string, string> *solver = new StringReverser();
    CacheManager<string, string> *cacheManager = new FileCacheManager();
    auto *clientHandler = new MyTestClientHandler(solver, cacheManager);
    server->open(atoi(argv[1]), *clientHandler, serverThread);
    //serverThread.join();
    delete (server);
    delete (solver);
    delete (cacheManager);
    delete (clientHandler);
    /*
    if ( argc <= 1)  {
        cout << ERROR_PORT << endl;
        return 0;
    }
    thread serverThread;
    server_side::Server *server = new MyParralelServer();
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
     */
}




