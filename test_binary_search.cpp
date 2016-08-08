#include <iostream>
#include <vector>

int NOT_FOUND = -1;

template <typename Comparable>
int binary_search (const std::vector<Comparable> & a, const Comparable & x) {
  int lo = 0, hi = a.size() - 1;

  while (lo <= hi) {
    int mid = (lo + hi) /2;
    if (a[mid] < x) {
      lo = mid + 1 ;
    } else if (a[mid] > x) {
      hi = mid - 1;
    } else {
      return mid;  
    }
  }
  return NOT_FOUND;
}

int main() {
  std::vector<int> a ;
  a.push_back(0);
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);
  a.push_back(6);
  a.push_back(7);
  a.push_back(8);
  a.push_back(9);
  a.push_back(10);
  int x = 11;
  std::cout << "find x=" << x <<" idx from a , "
	  << binary_search(a, x) << std::endl;
  return 0;
}
