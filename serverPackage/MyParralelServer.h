//
// Created by eliran on 1/13/19.
//

#ifndef SECONDPROJECT_MYPARRALELSERVER_H
#define SECONDPROJECT_MYPARRALELSERVER_H


#include <thread>
#include "Server.h"

class MyParralelServer : public server_side::Server{

private:
    thread serverThread1, serverrThread2, serverThread3, serverThread4, serverThread5;


public:

    void open(int port, ClientHandler& clientHandler);

};


#endif //SECONDPROJECT_MYPARRALELSERVER_H
