//
// Created by Stefanos Mitropoulos on 2019-05-17.
//

#include "SignalHandling.h"

void signalHandling::registerSignals() {

    std::signal(SIGABRT, signalHandling::sigabort_signal_handler);
    std::signal(SIGUSR1, signalHandling::sigusr1_signal_handler);

}

void signalHandling::sigabort_signal_handler(int signal) {
    spdlog::debug("Signal {} caught. Closing socket and exiting", signal);
    if (signalHandling::srvr::getInstance().isInit()) {
        close(8080);
    }
    exit(signal);
}

void signalHandling::sigusr1_signal_handler(int signal) {
    spdlog::debug("Signal {} caught. Denying connections.", signal);
    sServer::SocketServer::getInstance().setTerminateServer(true);
}
