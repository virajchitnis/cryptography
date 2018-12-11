#include <iostream>

using namespace std;

bool isCoPrime(int x, int y);
bool isNumberPrime(int n);

int main() {
  // Get two prime numbers
  int p = 0, q = 0, n, phi_n, e;
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

  // Compute n
  n = p * q;
  // Compute phi(n)
  phi_n = (p - 1) * (q - 1);

  // Select an e value
  e = 2;
  while (e < phi_n) {
    // e must be co-prime to n and phi_n and smaller than phi_n.
    if (isCoPrime(e, n) && isCoPrime(e, phi_n)) {
      break;
    }
    else {
      e++;
    }
  }

  cout << "p = " << p << ", q = " << q << ", n = " << n << ", \u03A6(n) = " << phi_n << ", e = " << e << endl;
}

bool isCoPrime(int x, int y) {
  if (y%x == 0) {
    return false;
  }
  return true;
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
