#include <iostream>
#include <unordered_map>

void solve() {
  int n;
  std::cin >> n;

  std::unordered_map<int, int> counts;
  for (int i = 0; i < 2 * n; i++) {
    int val;
    std::cin >> val;
    counts[val]++;
  }

  // if odd, doesn't matter how we split item contributes as 1
  // if even, upper bound is 2 to count
  // 4k = (2k + 1) + (2k - 1) = 2
  // 4k + 2 = (2k + 1) + (2k + 1) = 2
  // (1, 1, 2, 2, 2, 2) can only imbalance 2s or 1s
  // (1, 1, 2) (2, 2, 2) can split one of the two
  // (1, 2, 2) (1, 2, 2)
  // (1, 2, 3) (2, 2, 2) -> can split 4k to balance it
  // In which situation does the size imbalance become impossible to fix, making the upper bound unreachable?

  int num_odd = 0, num_4mod0 = 0, num_4mod2 = 0;
  for (auto &[key, value] : counts) {
      if (value % 2 == 1) {
          num_odd++;
      } else if (value % 4 == 0) {
          num_4mod0++;
      } else {
          num_4mod2++;
      }
  }

  int result;
  if (num_odd > 0 || num_4mod0 % 2 == 0) {
      result = num_odd + 2 * num_4mod0 + 2 * num_4mod2;
  } else {
      result = 2 * num_4mod2 + 2 * num_4mod0 - 2;
  }
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
