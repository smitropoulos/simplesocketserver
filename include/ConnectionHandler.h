//
// Created by Stefanos Mitropoulos on 2019-05-15.
//

#ifndef TCP_SERVER_THREADED_CONNECTIONHANDLER_H
#define TCP_SERVER_THREADED_CONNECTIONHANDLER_H


#include <string>
#include "CaesarCipher.h"

class ConnectionHandler {
private:
    Cipher *cipher{};
public:
    ConnectionHandler() = delete;

    explicit ConnectionHandler(const std::string &cipherName);

    ~ConnectionHandler() {
        if (cipher != nullptr) {
            delete (cipher);
        }
    }

    void *Handle(int socket) const;
};


#endif //TCP_SERVER_THREADED_CONNECTIONHANDLER_H
