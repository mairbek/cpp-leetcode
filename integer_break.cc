#include <iostream>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/integer-break/
// DP, O(N) time O(N) memory
namespace {
class Solution {
 public:
  int integerBreak(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      int result = 0;
      for (int j = 1; j < i; j++) {
        result = std::max(result, std::max(dp[i - j] * j, j * (i - j)));
      }
      dp[i] = result;
    }
    return dp[n];
  }
};
}  // namespace

using int64 = long long;

void solve(int n) {
  Solution sol;
  int result = sol.integerBreak(n);
  std::cout << n << " | " << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(1);
  solve(3);
  solve(7);
  solve(10);
  return 0;
}
