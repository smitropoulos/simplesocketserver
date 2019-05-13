//
// Created by Stefanos Mitropoulos on 2019-05-11.
//

#ifndef TCP_SERVER_THREADED_CAESARCIPHER_H
#define TCP_SERVER_THREADED_CAESARCIPHER_H

#include <string>

class CaesarCipher {
private:
    CaesarCipher() = default;
public:
    static CaesarCipher& getInstance(){
        static CaesarCipher xInstance;
        return xInstance;
    }
    std::string operate(std::string& input);

};

#endif //TCP_SERVER_THREADED_CAESARCIPHER_H
