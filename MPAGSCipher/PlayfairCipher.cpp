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
        char2Coord_[c] = coords;
        coord2Char_[coords] = c;
    }

    std::cout << key_ << "\n";

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
            } else if (working_string[i + 1] == 'J') {
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
        std::cout << "Decrypt not yet implemented" << std::endl;
        // TODO:  add decryption to playfair cipher
    };
    return output_string;
}

// The following code should split the input text into pairs, loop through the pairs and, if there are repeats,
// should split the repeats by inserting a X unless it is a repeated x and then should use Q?
// Next, the loop should find the positions of these two characters in the key and apply the three swapping rules
// (if same row, pick char to right in map, if same column swap with char below in map, and if not, then form a
// rectangle with two chars as corners.  swap the characters with the other corners (horizontally?).


std::string foo(std::string string) {
    return string;
}