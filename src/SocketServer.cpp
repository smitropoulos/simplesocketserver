//
// Created by smitropoulos on 5/11/19.
//

#include "SocketServer.h"

int sServer::SocketServer::initialiseSocket(unsigned int PortNumber) {

    unsigned int backlog = 10;

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
    server.sin_port = htons(PortNumber); // NOLINT(hicpp-signed-bitwise)

    if( bind(listeningSocket,(const struct sockaddr *)&server , sizeof(sockaddr_in)) < 0)
    {
        std::cerr << ("bind failed. Error\n");
        exit (-1);
    }

    std::cout << ("Bind succeeded\n");

    if (!listen(listeningSocket , static_cast<int>(backlog)) ){
        return listeningSocket;
    }

    return -1;
}

int sServer::SocketServer::handleRequests(ConnectionHandler &connectionHandler) {

    int client_sock;
    struct sockaddr client{};

    std::cout << ("Waiting for incoming connections...\n");
    size_t c = sizeof(struct sockaddr_in);

    ConnectionHandler requestHandler;
    requestHandler = std::move(connectionHandler);

    while( (client_sock = accept(listeningSocket, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");

        //Handle Requests Here
        //Use std::ref to create an rvalue ref to the object which will execute the Handle function.
        // Else, the object will be copied, the desctructor will be called and a non initialized pointer will be destroyed (boom)
        std::thread thread(&ConnectionHandler::Handle, std::ref(requestHandler), client_sock);
        thread.detach();

    }

    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }

    return 0;
}