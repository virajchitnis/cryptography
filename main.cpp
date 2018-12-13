/* Author: Viraj R Chitnis
 * Date: 12/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "CaesarCipher.h"

using namespace std;

int main(int argc, char const *argv[]) {
  string file_name;
  if (argc <= 1) {
    cout << "Enter file name> ";
    cin >> file_name;
  }
  else {
    file_name = argv[1];
  }
  ifstream ifs(file_name);
  string message;
  message.assign(istreambuf_iterator<char>(ifs), istreambuf_iterator<char>());

  cout << "\033[1;32mOriginal message:\033[0m " << endl << endl;
  cout << message << endl;
  CaesarCipher *cc = new CaesarCipher();
  string e_message = cc->encrypt(message, 15);
  cout << "\033[1;32mEncrypted message:\033[0m " << endl << endl << e_message << endl;
  string d_message = cc->decrypt(e_message, 15);
  cout << "\033[1;32mDecrypted message:\033[0m " << endl << endl << d_message << endl;
  return 0;
}
