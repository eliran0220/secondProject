#include <iostream>
#include "solverPackage/Solver.h"
#include "cachePackage/CacheManager.h"
#include "serverPackage/Server.h"
#include "serverPackage/MySerialServer.h"
#include "solverPackage/StringReverser.h"
#include "cachePackage/FileCacheManager.h"
#include "clientPackage/MyTestClientHandler.h"
#include "searchPackage/Searcher.h"
#include "searchPackage/State.h"
#include "test/MatrixDomain.h"
#include "searchPackage/BestFirstSearch.h"
#include "searchPackage/BFS.h"
#include "searchPackage/DFS.h"
#include "searchPackage/AStar.h"
#include "clientPackage/MyClientHandler.h"
#include "utils/SearchSolver.h"
#include "problemPackage/MatrixProblem.h"


void check(int argc, char *argv[]) {
    vector<vector<string>> matrix;
    vector<string> temp;
    temp.push_back("1");
    temp.push_back("2");
    temp.push_back("3");
    temp.push_back("4");
    matrix.push_back(temp);
    temp.clear();
    temp.push_back("0");
    temp.push_back("0");
    temp.push_back("0");
    temp.push_back("0");
    matrix.push_back(temp);
    temp.clear();
    temp.push_back("1");
    temp.push_back("1");
    temp.push_back("1");
    temp.push_back("1");
    matrix.push_back(temp);
    temp.clear();
    temp.push_back("0");
    temp.push_back("0");
    temp.push_back("0");
    temp.push_back("0");
    matrix.push_back(temp);
    temp.clear();
    temp.push_back("1");
    temp.push_back("1");
    matrix.push_back(temp);
    temp.clear();
    temp.push_back("3");
    temp.push_back("3");
    matrix.push_back(temp);
    temp.clear();


    SearchableMatrix *m = new SearchableMatrix(matrix);
    Searcher<Point *> *searcher = new AStar<Point *>();
    Solver<Searchable<Point *> *, vector<State<Point *> *>> *solver = new SearchSolver<Point *>(
            searcher);
    vector<State<Point *> *> v = solver->solver(m);
    cout << solver->solutionToString(v) << endl;
    cout << v[v.size() - 1]->getCost();
}


void serverCheck(int argc, char *argv[]) {
    server_side::Server *server = new MySerialServer();
    Searcher<Point *> *searcher = new BestFirstSearch<Point *>();
    Solver<Searchable<Point *> *, vector<State<Point *> *>> *solver = new SearchSolver<Point *>(
            searcher);
    CacheManager<string, string> *cacheManager = new FileCacheManager(argv[2]);
    ProblemCreator<Searchable<Point *> *> *problemCreator = new MatrixProblem();
    MyClientHandler<Point *> *clientHandler = new MyClientHandler<Point *>(
            solver, cacheManager, problemCreator);
    server->open(atoi(argv[1]), *clientHandler);
    sleep(60);
    delete (server);
    delete (solver);
    delete (searcher);
    delete (cacheManager);
    delete (clientHandler);
}


void matrixDomainCheck() {
    MatrixDomain *m = new MatrixDomain();
    BestFirstSearch<Point *> *bestFirstSearch = new BestFirstSearch<Point *>();
    bestFirstSearch->search(m);
}


void checkUnorder() {
    MyUnorderedSet<Point *> set;
    State<Point *> *p = new State<Point *>(new Point(1, 2), 3);
    set.insertState(p);
    p = new State<Point *>(new Point(1, 3), 3);
    set.insertState(p);
    p = new State<Point *>(new Point(1, 4), 3);
    set.insertState(p);
    p = new State<Point *>(new Point(1, 5), 3);
    set.insertState(p);
    p = new State<Point *>(new Point(1, 7), 3);
    set.contains(p);
}

int main(int argc, char *argv[]) {

    check(argc, argv);
    //matrixDomainCheck();
    //checkUnorder();

}
