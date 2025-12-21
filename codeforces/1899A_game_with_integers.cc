#include <iostream>

bool solve(int n) {
    if ((n-1) % 3 == 0) {
        return true;
    }
    if ((n+1) % 3 == 0) {
        return true;
    }
    return false;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::cout << (solve(n) ? "First" : "Second") << std::endl;
  }

  return 0;
}
