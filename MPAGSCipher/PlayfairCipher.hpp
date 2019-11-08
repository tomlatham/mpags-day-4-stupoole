//
// Created by stu on 08/11/2019.
//

#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include <string>
#include <vector>
#include <iostream>

class PlayfairCipher
{
public:

  explicit PlayfairCipher(std::string key);
  std::string setKey(const std::string& key);
  std::string applyCipher(std::string &input_string);

private:
  const std::vector<char> alphabet_ = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                       'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                                       'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                                       'X', 'Y', 'Z'};
  std::string key_ = "";
};

#endif // MPAGSCIPHER_PLAYFAIRCIPHER_HPP
