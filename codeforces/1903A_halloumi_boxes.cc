#include <iostream>
#include <vector>

bool solve2(int k, std::vector<int> const& a) {
  if (k > 1) {
    return true;
  }
  int prev = a[0];
  int i = 1;
  for (; i < a.size(); i++) {
    if (a[i] < prev) {
      break;
    }
    prev = a[i];
  }
  return i == a.size();
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::cout << (solve2(k, a) ? "YES" : "NO") << std::endl;
  }

  return 0;
}
