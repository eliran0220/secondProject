#ifndef MAINBOOT_H
#define MAINBOOT_H

#include "MySerialServer.h"
#include "../cachePackage/FileCacheManager.h"
#include "../searchPackage/AStar.h"
#include "../clientPackage/MyClientHandler.h"
#include "../utils/SearchSolver.h"
#include "../problemPackage/MatrixProblem.h"


#define ERROR "Missing port number"

namespace server_side {
    namespace boot {
        class Main {
        public:
            int main(int argc, char *argv[]) {
                if (argc <= 1) {
                    cout << ERROR << endl;
                    return 0;
                }
                thread serverThread;
                server_side::Server *server = new MySerialServer();
                Solver<string, string> *solver = new StringReverser();
                CacheManager<string, string> *cacheManager =
                        new FileCacheManager();
                auto *clientHandler = new MyTestClientHandler(solver,
                                                              cacheManager);
                server->open(atoi(argv[1]), *clientHandler, serverThread);
                serverThread.join();
                delete (server);
                delete (solver);
                delete (cacheManager);
                delete (clientHandler);
            }
        };
    }
}

#endif
