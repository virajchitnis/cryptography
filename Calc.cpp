/* Author: Viraj R Chitnis
 * Date: 11/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include "Calc.h"

bool Calc::isNumberPrime(int n) {
  if (n == 0) {
    return false;
  }
  else {
    for(int i = 2; i < n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
  }
  return true;
}

bool Calc::isCoPrime(int x, int y) {
  if (y%x == 0) {
    return false;
  }
  return true;
}
