/*
    C socket server example, handles multiple clients using threads
    Compile
    gcc server.c -lpthread -o server
*/

#include "Socket_Server.h"

int main() {
    Socket_Server::getInstance().initialiseServer(8080);
    Socket_Server::getInstance().operate();
}
