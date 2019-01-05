//
// Created by afik on 1/6/19.
//

#ifndef SECONDPROJECT_SERVER_H
#define SECONDPROJECT_SERVER_H

namespace server_side{
    class Server {
    virtual void open(int port) = 0;
    virtual bool shouldStop() = 0;
    virtual void close() = 0;

};
}
#endif //SECONDPROJECT_SERVER_H
