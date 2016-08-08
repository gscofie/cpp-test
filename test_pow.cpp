#include <iostream>

bool isEven(int n) {
  if (n%2 == 0)
    return true;
  return false;
} 

long pow(long x, int n) {
  if (n == 0) return 1;
  if (n == 1) return x;

  if (isEven(n)) {
    return pow(x * x, n/2);
  } else {
    return pow(x * x , n/2) * x;
  }
}

int main() {
  long x = 5;
  int n = 5;
  std::cout << x << " pow " << n << " equals " << pow(x, n) << std::endl;
}
