#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  // std::vector v;

  for (int i=0; i<10000; i++) {
    v.push_back(i);
  }

  std::cout << v.size() << std::endl;
  std::cout << v[20000] << std::endl;
}
