#include <iostream>
#include "solverPackage/Solver.h"
#include "cachePackage/CacheManager.h"
#include "serverPackage/Server.h"
#include "serverPackage/MySerialServer.h"
#include "solverPackage/StringReverser.h"
#include "cachePackage/FileCacheManager.h"
#include "clientPackage/MyTestClientHandler.h"


int main(int argc, char *argv[]) {
    server_side::Server* server = new MySerialServer();
    Solver<string, string>* solver = new StringReverser();
    CacheManager<string, string>* cacheManager = new  FileCacheManager("a.txt", "b.txt");
    ClientHandler* clientHandler = new MyTestClientHandler<string,string>(solver, cacheManager);
    server->open(atoi(argv[1]),*clientHandler);
    sleep(500);
    //delete(server);
    //delete(solver);
    //delete(cacheManager);
    //delete(clientHandler);
    return 0;
}