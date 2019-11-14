//
// Created by stu on 08/11/2019.


#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <string>
#include <map>
#include "CipherMode.hpp"
/**
 * \file PlayfairCipher.hpp
 * \brief  Contains declaration of PlayfairCipher Class
 */

/**
 * \class   PlayfairCipher
 * \brief Encrypt of decrypt text using the playfair cipher with given key string.
 */
class PlayfairCipher {
public:
    /**
     * \brief This class definition takes a string and generates a key from this
     * string
     * \param key is used to populate a 5x5 grid
     */
    explicit PlayfairCipher(const std::string &key);

    /**
     * \brief Applies the cipher to the code with the option
     * \param input_string input_string is the string to be encrypted or decrypted
     * \param cipherMode
     * \return the result of applying the cipher to input text
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
     * \brief Alphabet as a string for use in generating the key. Note that the J is missing.
     */
    const std::string alphabet_ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    /*
     * \brief 5x5 grid string
     */
    std::string key_ = "";

    // I would much rather use a tuple. A tuple would work both ways and would allow quick assignment to x and y from
    // char and visa versa
    using MapChar2Coord_ = std::map<char, std::pair<int, int>>;
    using MapCoord2Char_ = std::map<std::pair<int, int>, char>;
    MapChar2Coord_ char2Coord_;
    MapCoord2Char_ coord2Char_;
};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP
