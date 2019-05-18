//
// Created by Stefanos Mitropoulos on 2019-05-11.
//

#include "CaesarCipher.h"

std::string CaesarCipher::operate(std::string &input) {

    std::string message = input;
    char ch;
    int key = 1;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;

            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;

            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }

            message[i] = ch;
        }
    }

    return message;
}
