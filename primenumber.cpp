/* Author: Viraj R Chitnis
 * Date: 11/12/18
 * Copyright (c) 2018 Viraj Chitnis. All Rights Reserved.
 */

#include <iostream>
#include <csignal>
#include <time.h>
#include "Calc.h"

using namespace std;

int pcount = 0;
clock_t start;
double duration;

void signalHandler(int signum);
void showTimerAndCount();

int main() {
  // register signal SIGINT and signal handler
  signal(SIGINT, signalHandler);

  start = clock();

  int n = 1;
  while (true) {
    if (Calc::isNumberPrime(n)) {
      cout << n << endl;
      pcount++;
    }
    n++;
  }
  showTimerAndCount();
  return 0;
}

void signalHandler(int signum) {
  // cout << "Interrupt signal (" << signum << ") received." << endl;
  showTimerAndCount();
  exit(signum);
}

void showTimerAndCount() {
  duration = (clock() - start) / (double)CLOCKS_PER_SEC;
  int hours = duration / 3600;
  int minutes = (duration - (hours * 3600)) / 60;
  double seconds = duration - (minutes * 60);
  cout << endl << pcount << " prime numbers calculated in " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
}
