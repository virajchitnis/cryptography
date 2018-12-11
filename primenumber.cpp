#include <iostream>
#include <csignal>
#include "Calc.h"

using namespace std;

int pcount = 0;

void signalHandler(int signum);

int main() {
  // register signal SIGINT and signal handler
  signal(SIGINT, signalHandler);

  int n = 1;
  while (true) {
    if (Calc::isNumberPrime(n)) {
      cout << n << endl;
      pcount++;
    }
    n++;
  }
  cout << pcount << " prime numbers." << endl;
  return 0;
}

void signalHandler(int signum) {
  // cout << "Interrupt signal (" << signum << ") received." << endl;
  cout << endl << pcount << " prime numbers calculated so far." << endl;
  exit(signum);
}
