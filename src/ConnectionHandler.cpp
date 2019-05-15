//
// Created by Stefanos Mitropoulos on 2019-05-15.
//

#include "ConnectionHandler.h"
#include <unistd.h>
#include <sys/socket.h>

ConnectionHandler::ConnectionHandler(const std::string &cipherName) {
    if (cipherName == "caesar") {
        cipher = new CaesarCipher;
    }


}

void *ConnectionHandler::Handle(int socket) const {

    //Get the socket descriptor
    int sock = socket;
    int read_size;
    const char *message;
    char client_message[200];

    //Send some messages to the client
    message = "Greetings! I am your connection handler\n";
    write(sock, message, strlen(message));

    message = "Now type something and i shall apply the caesar cipher ot it \n";
    write(sock, message, strlen(message));

    //Receive a message from client
    while ((read_size = recv(sock, client_message, 200, 0)) > 0) {
        //end of string marker
        client_message[read_size] = '\0';

        std::string temp(client_message);
        temp = cipher->operate(temp);

        //Send the message back to client
        write(sock, temp.c_str(), strlen(temp.c_str()));

        //clear the message buffer
        memset(client_message, 0, 200);
    }

    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    return nullptr;
}

