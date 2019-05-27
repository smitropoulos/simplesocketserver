//
// Created by smitropoulos on 5/11/19.
//

#ifndef TCP_SERVER_THREADED_SOCKETSERVER_H
#define TCP_SERVER_THREADED_SOCKETSERVER_H

#include <string>
#include <iostream>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <thread>
#include <inet_sockets.h>

#include "LoggingUtility.h"
#include "CaesarCipher.h"
#include "RequestHandler.h"

namespace sServer {

    class SocketServer {
    private:
        bool TerminateServer{};
    public:
        void setTerminateServer(bool terminateServer);

    private:
        unsigned int portNumber{8080};
        bool init{};
        int listeningSocket{};

        explicit SocketServer(unsigned int port) : portNumber(port) {};

        SocketServer() = default;

        int initialiseSocket(unsigned int PortNumber);

      int handleRequests (RequestHandler& connectionHandler);

    public:
        static SocketServer &getInstance() {
            static SocketServer xInstance;
            return xInstance;
        }

        void initialise(unsigned int port) {
            portNumber = port;
            initialiseSocket(port);
            init = true;
        }

      bool isInit ()
      {
            return init;
        }

      int operate (RequestHandler& connectionHandler)
      {
            if (init) {
                handleRequests(connectionHandler);
            }
            spdlog::error("Server not initialised. Please initialize it first before running");
            return -1;
        }
    };

}

#endif //TCP_SERVER_THREADED_SOCKETSERVER_H
