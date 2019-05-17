//
// Created by Stefanos Mitropoulos on 2019-05-16.
//

#ifndef TCP_SERVER_THREADED_SIGNALHANDLING_H
#define TCP_SERVER_THREADED_SIGNALHANDLING_H

#include <csignal>
#include <iostream>
#include "SocketServer.h"

namespace signalHandling {
    typedef sServer::SocketServer srvr;

    void signal_handler(int signal) {
        std::cout << "Signal " << signal << " caught. Closing socket and exiting" << std::endl;
        if (srvr::getInstance().isInit()) {
            close(8080);
        }
        exit(signal);
    }

}
#endif //TCP_SERVER_THREADED_SIGNALHANDLING_H
