#ifndef MYSERIALSERVER_H
#define MYSERIALSERVER_H


#include <netinet/in.h>
#include <strings.h>
#include <pthread.h>
#include <cstring>
#include <iostream>
#include <thread>
#include "Server.h"
#include <unistd.h>

/**
 * MySerialServer class, creates a new serial server
 */
class MySerialServer : public server_side::Server {
    bool stop;
    thread serverThread;

public:

    /**
     * Function name: MySerialServer
     * The function operation: constructs a new MySerialServer
     */
    MySerialServer();

    /**
     * Function name: ~MySerialServer
     * The function operation: distructs the mySerialServer
     */
    ~MySerialServer();

    /**
     * Function name: open
     * The function operation: opens a server by a given port and clientHandler
     * @param port given port
     * @param clientHandler given clientHanlder
     */
    void open(int port, ClientHandler &clientHandler) override;

    /**
     * Function name: runServer
     * The function operation: runs the server
     * @param port given port
     * @param clientHandler given clientHandler
     * @param mySerialServer given MySerialServer
     */
    static void runServer(int port, ClientHandler *clientHandler, MySerialServer *mySerialServer);

    /**
     * Function name: shouldStop
     * The function operation: returns the stop value
     * @return bool
     */
    bool shouldStop() { return this->stop; }

    /**
     * Function name: closeServer
     * The function operation: sets the stop value to true
     */
    void closeServer() { this->stop = true; }

    /**
     * Function name: setStop
     * The function operation: sets the stop value to false
     */
    void setStop() { this->stop = false; }

};


#endif
