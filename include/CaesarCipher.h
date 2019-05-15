//
// Created by Stefanos Mitropoulos on 2019-05-11.
//

#ifndef TCP_SERVER_THREADED_CAESARCIPHER_H
#define TCP_SERVER_THREADED_CAESARCIPHER_H

#include "Cipher.h"

class CaesarCipher : public Cipher {
public:
    std::string operate(std::string &input) override;

};

#endif //TCP_SERVER_THREADED_CAESARCIPHER_H
