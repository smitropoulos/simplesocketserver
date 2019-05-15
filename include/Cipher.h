//
// Created by Stefanos Mitropoulos on 2019-05-15.
//

#ifndef TCP_SERVER_THREADED_CIPHER_H
#define TCP_SERVER_THREADED_CIPHER_H

#include <string>

class Cipher {

public:
    virtual std::string operate(std::string &input) = 0;

    virtual ~Cipher() = default;
};


#endif //TCP_SERVER_THREADED_CIPHER_H
