//
// Created by stu on 08/11/2019.
//

#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher(const std::string key) : key_{PlayfairCipher::setKey(key)} {

}

std::string PlayfairCipher::setKey(const std::string &key) {
  std::string key_string = key;
//
//  for (char& c : key)
//  {
//    if( c == 'J')
//    {
//      c = 'I';
//    }
//    if (key_string.find(c) != std::string::npos)
//    {
//      key_string += c;
//    }
//  }


  return key_string;
}
std::string PlayfairCipher::applyCipher(std::string &input_string) {
  std::cout << input_string << std::endl;
  return input_string;
}
