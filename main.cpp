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


int main(int argc, char *argv[]) {


    /*
     *
    MatrixDomain matrixDomain = MatrixDomain();
    BestFirstSearch<Point*>*  bestFirstSearch = new BestFirstSearch<Point*>();
    vector<State<Point*>*>path = bestFirstSearch->search(&matrixDomain);
    cout<< bestFirstSearch->getNumberOfNodesEvaluated()<<endl;

    int x=9;

    MyPriority<string>* priorityQueue = new MinPriorityQueue<string>();
    State<string>* s = new State<string>("q",7,1,2);
    s->setCostPath(7);
    priorityQueue->push(s);
    s = new State<string>("a",67,1,3);
    s->setCostPath(67);
    priorityQueue->push(s);
    s = new State<string>("a",9,1,3);
    s->setCostPath(9);
    priorityQueue->push(s);
    s = new State<string>("a",89,1,3);
    s->setCostPath(89);
    priorityQueue->push(s);
    s = new State<string>("a",19,1,3);
    s->setCostPath(19);
    priorityQueue->push(s);


    //s = priorityQueue.poll();
    while (!priorityQueue->isEmpty()) {
        s = priorityQueue->poll();
        cout<<s->getState()<<"-";
        cout<<s->getCost()<<endl;
    }
    */


    server_side::Server* server = new MySerialServer();
    Searcher<Point*>*  searcher = new BestFirstSearch<Point*>();
    Solver<Searchable<Point*>*, string> *solver = new SearchSolver<Point*>(searcher);
    CacheManager<string, string>* cacheManager = new  FileCacheManager(argv[2]);
    ProblemCreator<Searchable<Point*>*>* problemCreator = new MatrixProblem();
    MyClientHandler<Point*>* clientHandler = new MyClientHandler<Point*>(solver, cacheManager, problemCreator);
    server->open(atoi(argv[1]),*clientHandler);
    sleep(20);
    delete(server);
    delete(solver);
    delete (searcher);
    delete(cacheManager);
    delete(clientHandler);
    return 0;

}