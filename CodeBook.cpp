/* Author: Viraj R Chitnis
 * Date: 13/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include "CodeBook.h"

CodeBook::CodeBook() {
  // Do nothing.
}

int CodeBook::location_of_character(char c) {
  for (int i = 0; i < 26; i++) {
    if (_book[i] == c) {
      return i;
    }
  }
  return -1;
}
