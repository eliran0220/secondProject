//
// Created by eliran on 1/13/19.
//

#ifndef SECONDPROJECT_MYPARRALELSERVER_H
#define SECONDPROJECT_MYPARRALELSERVER_H


#include <thread>
#include <vector>
#include "Server.h"

using std::vector;

class MyParralelServer : public server_side::Server{
    bool stop;
    vector<thread> serverThreads;

public:

    /**
     * Function name: MySerialServer
     * The function operation: constructs a new MySerialServer
     */
    MyParralelServer();

    /**
     * Function name: ~MySerialServer
     * The function operation: distructs the mySerialServer
     */
    ~MyParralelServer();

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

    static void communicate(int sockfd, ClientHandler *clientHandler);

    static void openMainServerThread(int sockfd, ClientHandler *clientHandler, MyParralelServer* server);

};


#endif //SECONDPROJECT_MYPARRALELSERVER_H
