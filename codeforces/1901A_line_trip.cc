#include <iostream>
#include <vector>

int solve(std::vector<int> const& a, int x) {
  int prev = 0;
  int result = 0;
  int i = 0;
  for (; i < a.size() && a[i] <= x; i++) {
    int dist = a[i] - prev;
    if (dist > result) {
      result = dist;
    }
    prev = a[i];
  }
  int dist = (x - a[i - 1]) * 2;
  if (dist > result) {
    result = dist;
  }
  return result;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::cout << solve(a, x) << std::endl;
  }

  return 0;
}
