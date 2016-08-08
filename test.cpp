#include <iostream>
#include <vector>

int main() {
  std::cout << "hello " << std::endl;
  int n = 10; int m = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j++) {
      m = m + 1;
    }
  }

  std::cout << "m," << m << std::endl;
}
