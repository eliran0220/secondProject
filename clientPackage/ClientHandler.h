//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_CLIENTHANDLER_H
#define SECONDPROJECT_CLIENTHANDLER_H
using namespace std;

#include <istream>

class ClientHandler {
    virtual void handleClient(istream input, ostream output) = 0;
};
#endif //SECONDPROJECT_CLIENTHANDLER_H
