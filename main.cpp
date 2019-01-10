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
#include "utils/MaxPriorityQueue.h"
#include "utils/RegularQueue.h"
#include "test/MatrixDomain.h"
#include "searchPackage/BestFirstSearch.h"
#include "searchPackage/BFS.h"
#include "searchPackage/DFS.h"


int main(int argc, char *argv[]) {

    MatrixDomain matrixDomain = MatrixDomain();
    DFS<int>* bestFirstSearch = new DFS<int>();
    vector<State<int>*>path = bestFirstSearch->search(&matrixDomain);

    int x=9;
    /*
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

    /*
    server_side::Server* server = new MySerialServer();
    Solver<string, string>* solver = new StringReverser();
    CacheManager<string, string>* cacheManager = new  FileCacheManager("a.txt");
    ClientHandler* clientHandler = new MyTestClientHandler(solver, cacheManager);
    server->open(atoi(argv[1]),*clientHandler);
    sleep(20);
    int x = 3;
    cout<<"aa";
    delete(server);
    delete(solver);
    delete(cacheManager);
    delete(clientHandler);
    return 0;
     */
}