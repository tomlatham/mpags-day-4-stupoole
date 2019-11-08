//
// Created by stu on 08/11/2019.
//

#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher(const std::string &key) {
    PlayfairCipher::setKey(key);
}


void PlayfairCipher::setKey(const std::string &key) {
    key_ = key;
}


std::string PlayfairCipher::applyCipher(std::string &input_string, CipherMode cipherMode) const {
    if (cipherMode == CipherMode::Encrypt) {
        std::cout << input_string << std::endl;
    } else if (cipherMode == CipherMode::Decrypt) {
        std::cout << input_string << std::endl;
    };
    return input_string;
}

std::string foo(std::string string) {
    return string;
}