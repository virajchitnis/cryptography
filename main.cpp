/* Author: Viraj R Chitnis
 * Date: 12/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "CaesarCipher.h"
#include "VigenereCipher.h"

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
  string e_message = CaesarCipher::encrypt(message, 15);
  cout << "\033[1;32mEncrypted with Caesar Cipher:\033[0m " << endl << endl << e_message << endl;
  string d_message = CaesarCipher::decrypt(e_message, 15);
  cout << "\033[1;32mDecrypted message:\033[0m " << endl << endl << d_message << endl;

  string v_message = VigenereCipher::encrypt(message, "SMITHO");
  cout << "\033[1;32mEncrypted with Vigenere Cipher:\033[0m " << endl << endl << v_message << endl;
  string vd_message = VigenereCipher::decrypt(v_message, "SMITHO");
  cout << "\033[1;32mDecrypted with Vigenere Cipher:\033[0m " << endl << endl << vd_message << endl;

  return 0;
}
