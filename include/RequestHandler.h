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

class RequestHandler {
private:
    std::unique_ptr<Cipher> cipher;
    //Cipher *cipher{};
public:
  explicit RequestHandler (const std::string& cipherName);

  explicit RequestHandler () = default;

    void *Handle(int socket) const;

  RequestHandler& operator= (RequestHandler&& other) noexcept
  {
        if (this != &other) {
            this->cipher = std::move(other.cipher);
        }
        return *this;
    }

};


#endif //TCP_SERVER_THREADED_CONNECTIONHANDLER_H
