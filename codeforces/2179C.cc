#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

// Key idea: k = min(a), can x = a[i] for all i and x >= k. a[i] mod x = 0.
// if k > a[0], then a[0] % x[0] = a[0]. so a[1] % x[1] = a[0] => a[1] = q*x[1] + a[0]. x[1] = k
// a[1]- a[0] = q * k. For max k, q = 1.

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    int result = a[0];
    if (a.size() > 1) {
        result = std::max(result, a[1] - a[0]);
    }
    std::cout << result << std::endl;
  }
  return 0;
}
