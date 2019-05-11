//
// Created by smitropoulos on 5/11/19.
//

#include <netinet/in.h>
#include <iostream>
#include "Socket_Server.h"

int Socket_Server::initialiseSocket(unsigned int portNumber) {

    unsigned int listeningSocket{}, backlog = 10;

/*
    struct sockaddr_in {
        short            sin_family;   // e.g. AF_INET
        unsigned short   sin_port;     // e.g. htons(3490)
        struct in_addr   sin_addr;     // see struct in_addr, below
        char             sin_zero[8];  // zero this if you want to
    };

    struct in_addr {
        unsigned long s_addr;  // load with inet_aton()
    };
*/

    struct sockaddr_in server{};

    //Create socket
    listeningSocket = socket(AF_INET , SOCK_STREAM , 0);
    if (listeningSocket == -1)
    {
        std::cerr << ("Could not create socket\n");
    }
    std::cout << ("Socket created\n");

    //Prepare the socket for incoming connections
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(static_cast<int>(portNumber));

    //Bind
    if( bind(listeningSocket,(const struct sockaddr *)&server , sizeof(sockaddr_in)) < 0)
    {
        std::cerr << ("bind failed. Error\n");
        exit (-1);
    }
    std::cout << ("Bind succeeded\n");

    //Listen on socket
    if (!listen(listeningSocket , static_cast<int>(backlog)) ){
        return listeningSocket;
    }

    return -1;
}
