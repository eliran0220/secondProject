//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_CLIENTHANDLER_H
#define SECONDPROJECT_CLIENTHANDLER_H
using namespace std;

#include <istream>
#include <unistd.h>

#define END "end"
#define BUFFER_SIZE 1024
#define SEPERATOR ":"

class ClientHandler {
public:
    virtual void handleClient(int socket) = 0;
    virtual ~ClientHandler() {};
};
#endif //SECONDPROJECT_CLIENTHANDLER_H
