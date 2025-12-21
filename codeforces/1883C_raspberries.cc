#include <iostream>
#include <vector>

int solve(std::vector<int> const& a, int k) {
  int result = -1;
  int odd = 0;
  int even = 0;
  for (int i = 0; i < a.size(); i++) {
    int mod = (k - a[i] % k) % k;
    if (result == -1 || mod < result) {
      result = mod;
    }
    if (a[i] % 2 == 1) {
      odd++;
    } else {
      even++;
    }
  }
  if (k == 4) {
    // 2 or more even == 0
    if (even >= 2) {
        return 0;
    }
    // if one even
    if (even == 1) {
        return std::min(result, 1);
    }
    if (odd >= 2) {
        return std::min(result, 2);
    }
    return result;
  }
  return result;
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
    std::cout << solve(a, k) << std::endl;
  }

  return 0;
}
