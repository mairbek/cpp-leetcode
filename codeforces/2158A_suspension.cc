#include <iostream>

void solve() {
  int n, y, r;
  std::cin >> n >> y >> r;

  int result = std::min(n, (y / 2 + r));

  std::cout << result << std::endl;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
