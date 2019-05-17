//
// Created by Stefanos Mitropoulos on 2019-05-15.
//

#ifndef TCP_SERVER_THREADED_CONNECTIONHANDLER_H
#define TCP_SERVER_THREADED_CONNECTIONHANDLER_H


#include <string>
#include <unistd.h>
#include <sys/socket.h>

#include "LoggingUtility.h"
#include "CaesarCipher.h"

class ConnectionHandler {
private:
    std::unique_ptr<Cipher> cipher;
    //Cipher *cipher{};
public:
    explicit ConnectionHandler(const std::string &cipherName);

    explicit ConnectionHandler() = default;
    void *Handle(int socket) const;

    ConnectionHandler &operator=(ConnectionHandler &&other) noexcept {
        if (this != &other) {
            this->cipher = std::move(other.cipher);
        }
        return *this;
    }

};


#endif //TCP_SERVER_THREADED_CONNECTIONHANDLER_H
