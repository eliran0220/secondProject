//
// Created by eliran on 1/14/19.
//

#ifndef SECONDPROJECT_MAINBOOT_H
#define SECONDPROJECT_MAINBOOT_H

#include "Server.h"
#include "MySerialServer.h"

namespace server_side {
    namespace boot {
        class Main;
    }
}

class server_side::boot::Main {
public:
    int main(int argc, char *argv[]) {
        Server *server = new MySerialServer();
        Solver<string, string> *solver = new StringReverser();
        CacheManager<string, string> *cacheManager = new FileCacheManager(
                "a.txt");
        ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
        server->open(atoi(argv[1]), *clientHandler);
        sleep(20);
        delete (server);
        delete (solver);
        delete (cacheManager);
        delete (clientHandler);
    }
};

#endif //SECONDPROJECT_MAINBOOT_H
