#include <iostream>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int k;
    std::cin >> k;
    int x;
    std::cin >> x;

    std::cout << (k*x) + 1 << std::endl;
  }
  return 0;
}
