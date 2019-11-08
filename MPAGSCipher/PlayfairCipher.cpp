//
// Created by stu on 08/11/2019.
//


#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher(const std::string &key) {
    PlayfairCipher::setKey(key);
}


void PlayfairCipher::setKey(const std::string &key) {
    // std::string string = key + alphabet_;
    key_ = key + alphabet_;
    std::string used_letters;
    MapChar2Coord_ char2Coord;
    MapCoord2Char_ coord2Char;

    // Removes non alpha characters
    key_.erase(std::remove_if(key_.begin(), key_.end(), [](char c) { return !isalpha(c); }),
               key_.end());

    // ensures all chars are upper case
    std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper);

    // Converts I to J
    std::transform(key_.begin(), key_.end(), key_.begin(),
                   [](char c) { return (c == 'J') ? 'I' : c; });

    // removes duplicated letters
    key_.erase(std::remove_if(key_.begin(), key_.end(),
                              [&used_letters](char c) {
                                  // if the string returns matching values, then add to used and don't erase
                                  if (used_letters.find(c) == std::string::npos) {
                                      used_letters += c;
                                      return false;
                                  } else {
                                      return true;
                                  }
                              }), key_.end());

    // generates coordinate maps from coordinate to char and visa versa
    for (size_t i{0}; i < key_.size(); i++) {
        auto coords = std::make_pair(i % 5, i / 5);
        char c = key_[i];
        char2Coord[c] = coords;
        coord2Char[coords] = c;
    }

    std::cout << key_ << "\n";

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