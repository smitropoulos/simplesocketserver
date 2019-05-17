#include "SignalHandling.h"
#include "SocketServer.h"
#include "ConnectionHandler.h"
#include "LoggingUtility.h"
#include "ArgHandler.h"

typedef sServer::SocketServer srvr;

int main(int argc, char *argv[]) {

    ArgHandler::handleArg(argc, argv);

    // Install signal handlers
    signalHandling::registerSignals();
    ConnectionHandler connHandler("caesar");

    srvr::getInstance().initialise(8080);
    srvr::getInstance().operate(connHandler);

}
