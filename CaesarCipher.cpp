/* Author: Viraj R Chitnis
 * Date: 12/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include "CaesarCipher.h"

CaesarCipher::CaesarCipher() {
  // Do nothing.
}

string CaesarCipher::encrypt(string message, int key) {
  string ret = "";
  for (char c : message) {
    bool isCapital = isupper(c);
    if (isCapital) {
      c = tolower(c);
    }
    int loc = location_of_character(c);
    if (loc > -1) {
      int new_loc = (loc + key) % 26;
      if (new_loc < 0) {
        new_loc += 26;
      }
      char e_c = _book[new_loc];
      if (isCapital) {
        e_c = toupper(e_c);
      }
      ret.push_back(e_c);
    }
    else {
      ret.push_back(c);
    }
  }
  return ret;
}

string CaesarCipher::decrypt(string code, int key) {
  string ret = "";
  for (char c : code) {
    bool isCapital = isupper(c);
    if (isCapital) {
      c = tolower(c);
    }
    int loc = location_of_character(c);
    if (loc > -1) {
      int new_loc = ((loc - key) % 26);
      if (new_loc < 0) {
        new_loc += 26;
      }
      char d_c = _book[new_loc];
      if (isCapital) {
        d_c = toupper(d_c);
      }
      ret.push_back(d_c);
    }
    else {
      ret.push_back(c);
    }
  }
  return ret;
}

int CaesarCipher::location_of_character(char c) {
  for (int i = 0; i < 26; i++) {
    if (_book[i] == c) {
      return i;
    }
  }
  return -1;
}
