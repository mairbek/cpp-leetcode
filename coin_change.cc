#include <iostream>
#include <vector>

namespace {
// https://leetcode.com/problems/coin-change/submissions/
// DP O(N) time O(N) space
class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      dp[i] = 0;
      for (auto& c : coins) {
        if (c > i) {
          continue;
        }
        if (i == c) {
          dp[i] = 1;
          break;
        }
        if (dp[i - c] > 0) {
          if (dp[i] == 0) {
            dp[i] = 1 + dp[i - c];
          } else {
            dp[i] = std::min(dp[i], 1 + dp[i - c]);
          }
        }
      }
    }

    return dp[amount] == 0 ? -1 : dp[amount];
  }
};
}  // namespace

using int64 = long long;

void solve(std::vector<int> v, int n) {
  Solution sol;
  int result = sol.coinChange(v, n);
  std::cout << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<int>{474, 83, 404, 3}, 264);
  return 0;
}