//
// Created by smitropoulos on 5/11/19.
//

#include <netinet/in.h>
#include <iostream>
#include <zconf.h>
#include "Socket_Server.h"


void *connection_handler(void *socket_desc)
{
    //Get the socket descriptor
    int sock = *(int*)socket_desc;
    int read_size;
    char *message , client_message[2000];

    //Send some messages to the client
    message = "Greetings! I am your connection handler\n";
    write(sock , message , strlen(message));

    message = "Now type something and i shall repeat what you type \n";
    write(sock , message , strlen(message));

    //Receive a message from client
    while( (read_size = recv(sock , client_message , 2000 , 0)) > 0 )
    {
        //end of string marker
        client_message[read_size] = '\0';

        //Send the message back to client
        write(sock , client_message , strlen(client_message));

        //clear the message buffer
        memset(client_message, 0, 2000);
    }

    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("recv failed");
    }


    sleep(10);

    return 0;
}

int Socket_Server::initialiseSocket(unsigned int portNumber) {

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

int Socket_Server::handleRequests() {

    int client_sock;
    struct sockaddr client{};
    //Accept and incoming connection
    std::cout << ("Waiting for incoming connections...\n");
    size_t c = sizeof(struct sockaddr_in);

    pthread_t thread_id;

    while( (client_sock = accept(listeningSocket, (struct sockaddr *)&client, (socklen_t*)&c)) )
    {
        puts("Connection accepted");

        if( pthread_create( &thread_id , NULL ,  connection_handler,  (void*) &client_sock) < 0)
        {
            perror("could not create thread");
            return 1;
        }

        //Now join the thread , so that we dont terminate before the thread
        //pthread_join( thread_id , NULL);
        puts("Handler assigned");
    }

    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }

    return 0;
}


