#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
using namespace std;

#include <istream>
#include <unistd.h>

/**
 * ClientHandler class
 */
class ClientHandler {
public:

    /**
     * Function name: handleClient
     * The function operation: the handleClient is responsible of
     * creating the problem given by the user, search for the solution,
     * if finds takes it from the cache if the problem isn't found, makes the
     * process of "creating" the problem, and solving it
     * saving it and return the solution
     * @param socket given socket
     */
    virtual void handleClient(int socket) = 0;

    /**
     * Function name: ~ClientHandler
     * The function operation: destructs the ClientHandler
     */
    virtual ~ClientHandler() = default;
};

#endif
