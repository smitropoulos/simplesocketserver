//
// Created by smitropoulos on 5/11/19.
//

#ifndef TCP_SERVER_THREADED_SOCKET_SERVER_H
#define TCP_SERVER_THREADED_SOCKET_SERVER_H
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <thread>
#include "CaesarCipher.h"

void *connection_handler(void *socket_desc);

class Socket_Server {
private:
    unsigned int portNumber{8080};
    bool init{};
    int listeningSocket{};
    explicit Socket_Server(unsigned int port): portNumber(port){};
    Socket_Server() = default;

    int initialiseSocket(unsigned int PortNumber);
    int handleRequests();
public:
    static Socket_Server& getInstance(){
        static Socket_Server xInstance;
        return xInstance;
    }
    void initialiseServer(unsigned int port){
        portNumber = port;
        initialiseSocket(port);
        init = true;
    }
    int operate(){
        if (init){
            handleRequests();
        }
        std::cerr << "Server not initialised. Please initialize it first before running\n";
        return -1;
    }
};


#endif //TCP_SERVER_THREADED_SOCKET_SERVER_H
