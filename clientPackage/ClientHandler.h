//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_CLIENTHANDLER_H
#define SECONDPROJECT_CLIENTHANDLER_H
using namespace std;

#include <istream>

class ClientHandler {
public:
    virtual void handleClient(string input) = 0;
};
#endif //SECONDPROJECT_CLIENTHANDLER_H
