#include <iostream>
#include "Calc.h"

using namespace std;

const int k = 2;

int main() {
  // Get two prime numbers
  int p = 0, q = 0, n, phi_n, e, d;
  do {
    cout << "Enter first prime number: ";
    cin >> p;
    if (!Calc::isNumberPrime(p)) {
      cout << p << " is not prime, try again." << endl;
    }
  } while (!Calc::isNumberPrime(p));
  do {
    cout << "Enter second prime number: ";
    cin >> q;
    if (!Calc::isNumberPrime(q)) {
      cout << q << " is not prime, try again." << endl;
    }
  } while (!Calc::isNumberPrime(q));

  // Compute n
  n = p * q;
  // Compute phi(n)
  phi_n = (p - 1) * (q - 1);

  // Select an e value
  e = 2;
  while (e < phi_n) {
    // e must be co-prime to n and Φ(n) and smaller than Φ(n).
    if (Calc::isCoPrime(e, n) && Calc::isCoPrime(e, phi_n)) {
      break;
    }
    else {
      e++;
    }
  }

  // Calculate d
  d = ((k * phi_n) + 1) / e;

  cout << "p = " << p << ", q = " << q << ", n = " << n << ", \u03A6(n) = " << phi_n << ", e = " << e << ", d = " << d << endl;

  string msg, cmsg = "";
  cout << "Enter message: ";
  cin >> msg;
  for (char m : msg) {
    int c = (int(m) ^ e) % n;
    char c_char = char(c);
    cmsg.push_back(c_char);
    cout << m << ", ASCII value: " << int(m) << ", encrypted ASCII: " << c << ", encrypted character: " << c_char << endl;
  }

  cout << "Encrypted message: " << cmsg << endl;

  return 0;
}
