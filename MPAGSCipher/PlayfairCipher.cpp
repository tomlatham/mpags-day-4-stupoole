//
// Created by stu on 08/11/2019.
//

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#include "PlayfairCipher.hpp"
#include <iostream>
#include <string>
#include <algorithm>

PlayfairCipher::PlayfairCipher(const std::string &key) {
    this->setKey(key);
}


void PlayfairCipher::setKey(const std::string &key) {
    // std::string string = key + alphabet_;
    key_ = key + alphabet_;

    // Removes non alpha characters
    key_.erase(std::remove_if(key_.begin(), key_.end(), [](char c) { return !isalpha(c); }),
               key_.end());

    // ensures all chars are upper case
    std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper);

    // Converts J to I
    std::transform(key_.begin(), key_.end(), key_.begin(),
                   [](char c) { return (c == 'J') ? 'I' : c; });

    // removes duplicated letters
    std::string used_letters;
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
        char2Coord_[c] = coords;
        coord2Char_[coords] = c;
    }

//    std::cout << key_ << "\n";

}

std::string PlayfairCipher::applyCipher(const std::string &input_string, const CipherMode cipherMode) const {
    std::string working_string = input_string;
    std::string output_string;

    if (cipherMode == CipherMode::Encrypt) {
        for (size_t i = 0; i < working_string.length(); i += 2) {
            // Appends Z if the string is odd in length in the last loop
            if (i + 1 >= working_string.length()) {
                if (working_string[i] == 'Z') {
                    working_string += 'X';
                } else {
                    working_string += 'Z';
                }
            }

            // Swaps J for I before checking for duplicates
            if (working_string[i] == 'J') {
                working_string[i] = 'I';
            }


            if (working_string[i + 1] == 'J') {
                working_string[i + 1] = 'I';
            }

            // Checks for duplicate letters and inserts appropriately
            if (working_string[i] == working_string[i + 1]) {
                if (working_string[i] == 'X') {
                    working_string.insert(i + 1, "Q");
                } else {
                    working_string.insert(i + 1, "X");
                }
            }

            // extracts x and y coords for input characters in the key
            auto first_coord = char2Coord_.at(working_string[i]);
            auto second_coord = char2Coord_.at(working_string[i + 1]);
            int first_x = first_coord.first;
            int first_y = first_coord.second;
            int second_x = second_coord.first;
            int second_y = second_coord.second;

            // Finds the correct coordinates for the substitution
            if (first_x == second_x) {
                first_y = (first_y + 1) % 5;
                second_y = (second_y + 1) % 5;
            } else if (first_y == second_y) {
                first_x = (first_x + 1) % 5;
                second_x = (second_x + 1) % 5;
            } else {
                std::swap(first_x, second_x);
            }

            // appends the two substitution characters to output array
            output_string += coord2Char_.at(std::make_pair(first_x, first_y));
            output_string += coord2Char_.at(std::make_pair(second_x, second_y));

        };
//        std::cout << "input:  " << input_string << "\noutput: " << output_string << std::endl;

    } else if (cipherMode == CipherMode::Decrypt) {
      
        for (size_t i = 0; i < working_string.length(); i += 2) {

            // extracts x and y coords for input characters in the key
            auto first_coord = char2Coord_.at(working_string[i]);
            auto second_coord = char2Coord_.at(working_string[i + 1]);
            int first_x = first_coord.first;
            int first_y = first_coord.second;
            int second_x = second_coord.first;
            int second_y = second_coord.second;

            // Finds the correct coordinates for the substitution
            if (first_x == second_x) {
                first_y = (first_y + 5 - 1) % 5;
                second_y = (second_y + 5 - 1) % 5;
            } else if (first_y == second_y) {
                first_x = (first_x + 5 - 1) % 5;
                second_x = (second_x + 5 - 1) % 5;
            } else {
                std::swap(first_x, second_x);
            }

            // appends the two substitution characters to output array
            output_string += coord2Char_.at(std::make_pair(first_x, first_y));
            output_string += coord2Char_.at(std::make_pair(second_x, second_y));
        };
      
//        std::cout << "input:  " << input_string << "\noutput: " << output_string << std::endl;

    }
  
    return output_string;
}

