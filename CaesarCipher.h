/* Author: Viraj R Chitnis
 * Date: 12/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <string>
#include <ctype.h>
#include "CodeBook.h"

using namespace std;

#ifndef CAESARCIPHER
#define CAESARCIPHER
class CaesarCipher {
public:
  static string encrypt(string message, int key);
  static string decrypt(string code, int key);
};
#endif
