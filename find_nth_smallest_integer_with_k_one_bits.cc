#include <iostream>

namespace {

class Solution {
 public:
  long long nthSmallest(long long n, int k) {
    std::vector<std::vector<long long>> comb(51, std::vector<long long>(51, 0));
    for (int n = 0; n <= 50; n++) {
      comb[n][0] = 1;
      for (int k = 1; k <= n; k++) {
        comb[n][k] = comb[n - 1][k - 1] + comb[n - 1][k];
      }
    }
    long long result = 0;
    while (k > 0) {
      int m = k - 1;
      long long count = 0;
      while (count + comb[m][k - 1] < n) {
        count += comb[m][k - 1];
        m++;
      }
      result |= 1LL << m;
      n -= count;
      k--;
    }
    return result;
  }
};
}  // namespace

void solve(long long n, int k, long long expected) {
  Solution sol;
  long long result = sol.nthSmallest(n, k);
  std::cout << "n=" << n << ", k=" << k << " => " << result
            << " (expected: " << expected << ")" << std::endl;
}

int main(int argc, char const** argv) {
  solve(4, 2, 9);
  solve(3, 1, 4);
  return 0;
}
