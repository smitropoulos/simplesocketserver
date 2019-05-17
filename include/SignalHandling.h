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

    void registerSignals();

    void sigabort_signal_handler(int signal);

    void sigusr1_signal_handler(int signal);

}
#endif //TCP_SERVER_THREADED_SIGNALHANDLING_H
