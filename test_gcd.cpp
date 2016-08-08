#include <iostream>

int gcd(long m, long n) {
  while (n != 0) {
    std::cout << "Line:" << __LINE__ << ": m = " << m<<",n = " << n << std::endl;
    long rem = m % n;
    std::cout << "m = " << m<<",n = " << n << ", rem = " <<rem << std::endl;
    m = n;
    n = rem;
  }
  return m;
}

int main() {
  long m = 1989, n = 1590 ;
  std::cout << "m = " << m<<",n = " << n << ", max gcd = " << gcd(m,n) << std::endl;
}
