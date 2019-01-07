//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_MYSERIALSERVER_H
#define SECONDPROJECT_MYSERIALSERVER_H


#include <netinet/in.h>
#include <strings.h>
#include <pthread.h>
#include <zconf.h>
#include <cstring>
#include <iostream>
#include <thread>
#include "Server.h"

class MySerialServer : public server_side::Server{
    bool stop;
    thread serverThread;

public:
    MySerialServer();
    ~MySerialServer();
    void open(int port, ClientHandler& clientHandler) override;

    static void runServer(int port, ClientHandler* clientHandler, MySerialServer* mySerialServer);

    bool shouldStop(){ return this->stop;}
    void closeServer(){this->stop = true;}
    void setStop() {this->stop = false;}

};


#endif //SECONDPROJECT_MYSERIALSERVER_H
