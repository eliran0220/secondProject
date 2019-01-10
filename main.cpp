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


int main(int argc, char *argv[]) {
    MyPriorityQueue<int> priorityQueue;
    State<int>* s = new State<int>(7);

    priorityQueue.push(s);
    priorityQueue.push(new State<int>(67));
    priorityQueue.push(new State<int>(4));
    priorityQueue.push(new State<int>(8));
    priorityQueue.push(new State<int>(9));
    priorityQueue.push(new State<int>(0));


    while (!priorityQueue.isEmpty()) {
        //s = priorityQueue.poll();
        //cout<<<<endl;
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