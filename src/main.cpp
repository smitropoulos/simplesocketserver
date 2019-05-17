#include "SignalHandling.h"
#include "SocketServer.h"
#include "ConnectionHandler.h"

typedef sServer::SocketServer srvr;

int main() {

    // Install a signal handler
    std::signal(SIGABRT, signalHandling::signal_handler);

    ConnectionHandler connHandler("caesar");

    srvr::getInstance().initialise(8080);
    srvr::getInstance().operate(connHandler);

}
