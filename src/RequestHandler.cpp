//
// Created by Stefanos Mitropoulos on 2019-05-15.
//

#include <memory>
#include "RequestHandler.h"

RequestHandler::RequestHandler (const std::string& cipherName)
{
    if (cipherName == "caesar") {
        cipher = std::make_unique<CaesarCipher>();
    }
}

void *RequestHandler::Handle (int socket) const
{

    //Get the socket descriptor
    int sock = socket;
    int read_size;
    const char *message;
    char client_message[200];

    //Send some messages to the client
  message = "Greetings! I am your connection handler! Now type something and i shall apply the caesar cipher to it!\n";
    write(sock, message, strlen(message));

    //Receive a message from client
    while ((read_size = recv(sock, client_message, 200, 0)) > 0) {
        //End of Message marker. This is imperative for the client to know that it read the whole message!
        client_message[read_size] = '\0';

        std::string temp(client_message);
        temp = cipher->operate(temp);

        //Send the message back to client
        write(sock, temp.c_str(), strlen(temp.c_str()));

        //clear the message buffer
        memset(client_message, 0, 200);
    }

    if (read_size == 0) {
        spdlog::debug("Client disconnected");
    } else if (read_size == -1) {
        spdlog::error ("recv failed: {}", errno);
    }

    return nullptr;
}

