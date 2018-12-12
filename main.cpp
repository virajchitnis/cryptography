/* Author: Viraj R Chitnis
 * Date: 12/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include "CaesarCipher.h"

using namespace std;

int main(int argc, char const *argv[]) {
  cout << "Enter string to encrypt> ";
  string message;
  cin >> message;
  CaesarCipher *cc = new CaesarCipher();
  string e_message = cc->encrypt(message, 5);
  cout << "Encrypted message: " << e_message << endl;
  string d_message = cc->decrypt(e_message, 5);
  cout << "Decrypted message: " << d_message << endl;
  return 0;
}
