//
// Created by stu on 08/11/2019.
//

#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <string>
#include <vector>
#include <iostream>
#include "CipherMode.hpp"

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
    std::string applyCipher(std::string &input_string, CipherMode cipherMode) const;

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
    const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                         'H', 'I', 'K', 'L', 'M', 'N', 'O',
                                         'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                                         'X', 'Y', 'Z'};
    /**
     * \brief 5x5 grid string
     */
    std::string key_ = "";
};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP
