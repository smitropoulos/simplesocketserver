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
#include "CaesarCipher.h"
#include "ConnectionHandler.h"

namespace sServer {

    class SocketServer {
private:
    unsigned int portNumber{8080};
    bool init{};
    int listeningSocket{};

        explicit SocketServer(unsigned int port) : portNumber(port) {};

        SocketServer() = default;

    int initialiseSocket(unsigned int PortNumber);

        int handleRequests(ConnectionHandler &connectionHandler);
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

        inline bool isInit() {
            return init;
        }

        int operate(ConnectionHandler &connectionHandler) {
        if (init){
            handleRequests(connectionHandler);
        }
        std::cerr << "Server not initialised. Please initialize it first before running\n";
        return -1;
    }
};

}

#endif //TCP_SERVER_THREADED_SOCKETSERVER_H
