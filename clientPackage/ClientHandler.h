//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_CLIENTHANDLER_H
#define SECONDPROJECT_CLIENTHANDLER_H
using namespace std;

#include <istream>
#include <unistd.h>

class ClientHandler {
public:
    virtual void handleClient(int socket) = 0;
};
#endif //SECONDPROJECT_CLIENTHANDLER_H
