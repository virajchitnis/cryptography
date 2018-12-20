#include "VigenereCipher.h"

string VigenereCipher::encrypt(string message, string key) {
  string ret = "";
  int message_len = message.length(), key_len = key.length();
  int *keys = new int[key_len];

  CodeBook *cb = new CodeBook();

  for (int i = 0; i < key_len; i++) {
    char k = key[i];
    keys[i] = cb->location_of_character(k);
  }

  string *columns = new string[key_len];
  for (int i = 0; i < message_len; i += key_len) {
    for (int j = 0; j < key_len; j++) {
      int tot_loc = i + j;
      if (tot_loc < message_len) {
        columns[j].push_back(message[tot_loc]);
      }
    }
  }

  string *e_columns = new string[key_len];
  for (int i = 0; i < key_len; i++) {
    e_columns[i] = CaesarCipher::encrypt(columns[i], keys[i]);
  }

  for (int i = 0; i < ((message_len / key_len) + 1); i++) {
    for (int j = 0; j < key_len; j++) {
      string col = e_columns[j];
      int cl = col.length();
      if (i < cl) {
        ret.push_back(col[i]);
      }
    }
  }

  return ret;
}

string VigenereCipher::decrypt(string message, string key) {
  string ret = "";
  int message_len = message.length(), key_len = key.length();
  int *keys = new int[key_len];

  CodeBook *cb = new CodeBook();

  for (int i = 0; i < key_len; i++) {
    char k = key[i];
    keys[i] = cb->location_of_character(k);
  }

  string *columns = new string[key_len];
  for (int i = 0; i < message_len; i += key_len) {
    for (int j = 0; j < key_len; j++) {
      int tot_loc = i + j;
      if (tot_loc < message_len) {
        columns[j].push_back(message[tot_loc]);
      }
    }
  }

  string *e_columns = new string[key_len];
  for (int i = 0; i < key_len; i++) {
    e_columns[i] = CaesarCipher::decrypt(columns[i], keys[i]);
  }

  for (int i = 0; i < ((message_len / key_len) + 1); i++) {
    for (int j = 0; j < key_len; j++) {
      string col = e_columns[j];
      int cl = col.length();
      if (i < cl) {
        ret.push_back(col[i]);
      }
    }
  }

  return ret;
}
