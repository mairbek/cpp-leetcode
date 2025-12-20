#include <iostream>
#include <vector>

bool solve(std::vector<int> const& a) {
  int min = 0;
  for (int i = 1; i < a.size(); i++) {
    if (min == 0 || min > a[i]) {
      min = a[i];
    }
  }
  return a[0] > min;
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
