/* Author: Viraj R Chitnis
 * Date: 12/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <string>

using namespace std;

#ifndef CAESARCIPHER
#define CAESARCIPHER
class CaesarCipher {
private:
  const char _book[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
  };
  int location_of_character(char c);
public:
  CaesarCipher();
  string encrypt(string message, int key);
  string decrypt(string code, int key);
};
#endif
