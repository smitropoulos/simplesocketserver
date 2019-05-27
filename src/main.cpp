#include "SignalHandling.h"
#include "SocketServer.h"
#include "RequestHandler.h"
#include "LoggingUtility.h"
#include "ArgHandler.h"

typedef sServer::SocketServer srvr;

int main(int argc, char *argv[]) {

  spdlog::info ("Starting server");

    ArgHandler::handleArg(argc, argv);
    // Install signal handlers
    signalHandling::registerSignals();
  srvr::getInstance ().initialise (8080);

  RequestHandler handler ("caesar");
  srvr::getInstance ().operate (handler);

}