#include <iostream>

using namespace std;

bool isNumberPrime(int n);

int main() {
  // Get two prime numbers
  int p = 0, q = 0, n, phi_n;
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

  n = p * q;
  phi_n = (p - 1) * (q - 1);

  cout << "p = " << p << ", q = " << q << ", n = " << n << ", \u03A6(n) = " << phi_n << endl;
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
