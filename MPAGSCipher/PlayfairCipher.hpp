//
// Created by stu on 08/11/2019.
//

#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "CipherMode.hpp"
#include <iterator>
#include <algorithm>
#include <map>
#include <tuple>



class PlayfairCipher {
public:
    /**
     * \brief This class definition takes a string and generates a key from this
     * string
     * \param key is a keys sting equivalent to a 5x5 grid
     */
    explicit PlayfairCipher(const std::string &key);

    /**
     * \brief Applies the cipher to the code with the option
     * \param input_string is the string to be encrypted
     * \return
     */
    std::string applyCipher(const std::string &input_string, CipherMode cipherMode) const;

private:
    /**
   * \brief
   * \param key
   * \returns returns 5x5 key grid
   */
    void setKey(const std::string &key);

    /**
     * \brief Alphabet as a vector of chars for use in generating the key. Note that the J is missing.
     */
    const std::string alphabet_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    /*
     * \brief 5x5 grid string
     */
    std::string key_ = "";

    // I would much rather use a tuple. A tuple would work both ways and would allow quick assignment to x and y from
    // char and visa versa
//    typedef key_map_ = tuple<char, int, int>;
    using MapChar2Coord_ = std::map<char, std::tuple<int, int>>;
    using MapCoord2Char_ = std::map<std::tuple<int, int>, char>;
    MapChar2Coord_ char2Coord_;
    MapCoord2Char_ coord2Char_;
};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP
