/* Author: Viraj R Chitnis
 * Date: 13/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <string>

using namespace std;

#ifndef CODEBOOK
#define CODEBOOK
class CodeBook {
private:
  const char _book[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
  };
public:
  CodeBook();
  int location_of_character(char c);
  char char_at_location(int loc) { return _book[loc]; }
};
#endif
