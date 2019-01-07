//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_SERVER_H
#define SECONDPROJECT_SERVER_H
#include "../clientPackage/ClientHandler.h"


namespace server_side{
    class Server {
    virtual void open(int port, ClientHandler& clientHandler) = 0;
    virtual bool shouldStop() = 0;
    virtual void setStop();
    virtual void closeServer() = 0;

};
}
#endif //SECONDPROJECT_SERVER_H
