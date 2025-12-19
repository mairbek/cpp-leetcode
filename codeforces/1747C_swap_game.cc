#include <iostream>

bool solve(std::vector<int> const& a) {
  int max = 0;
  for (int i = 1; i < a.size(); i++) {
    if (max == 0 || max < a[i]) {
      max = a[i];
    }
  }
  return (a[0] - max) > 0 && (a[0] - max) <= 2;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::cout << (solve(a) ? "Alice" : "Bob") << std::endl;
  }

  return 0;
}
