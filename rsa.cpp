#include <iostream>

using namespace std;

bool isNumberPrime(int n);

int main() {
  // Get two prime numbers
  int p = 0, q = 0;
  do {
    cout << "Enter first prime number: ";
    cin >> p;
    if (!isNumberPrime(p)) {
      cout << p << " is not prime, try again." << endl;
    }
  } while (!isNumberPrime(p));
  do {
    cout << "Enter second prime number: ";
    cin >> q;
    if (!isNumberPrime(q)) {
      cout << q << " is not prime, try again." << endl;
    }
  } while (!isNumberPrime(q));

  cout << "p = " << p << ", q = " << q << endl;
}

bool isNumberPrime(int n) {
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