#include <iostream>
#include "solverPackage/Solver.h"
#include "cachePackage/CacheManager.h"
#include "serverPackage/Server.h"
#include "serverPackage/MySerialServer.h"
#include "solverPackage/StringReverser.h"
#include "cachePackage/FileCacheManager.h"
#include "clientPackage/MyTestClientHandler.h"
//#include "searchPackage/Searcher.h"
#include "searchPackage/State.h"
#include "utils/MaxPriorityQueue.h"
#include "utils/RegularQueue.h"


int main(int argc, char *argv[]) {
    MyPriorityQueue<string>* priorityQueue = new RegularQueue<string>();
    State<string>* s = new State<string>("q",7);

    priorityQueue->push(s);
    priorityQueue->push(new State<string>("a",67));
    priorityQueue->push(new State<string>("b",4));
    priorityQueue->push(new State<string>("c",8));
    priorityQueue->push(new State<string>("d",9));
    priorityQueue->push(new State<string>("e",0));

    //s = priorityQueue.poll();
    while (!priorityQueue->isEmpty()) {
        s = priorityQueue->poll();
        cout<<s->getState()<<"-";
        cout<<s->getCost()<<endl;
    }


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