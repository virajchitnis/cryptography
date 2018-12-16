/* Author: Viraj R Chitnis
 * Date: 12/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <algorithm>
#include <string>
#include "CodeBook.h"
#include "CaesarCipher.h"

using namespace std;

#ifndef VIGENERECIPHER
#define VIGENERECIPHER
class VigenereCipher {
public:
  static string encrypt(string message, string key);
  static string decrypt(string code, string key);
};
#endif
