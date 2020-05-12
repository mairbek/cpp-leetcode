#include <iostream>
#include <unordered_map>
#include <vector>

namespace {

// https://leetcode.com/problems/perfect-squares/submissions/
// DP, O(N) time O(N) memory

class Solution {
 public:
  int numSquares(int n) {
    std::vector<int> squares;
    int dp[n + 1];
    dp[0] = 0;

    int next_sq = 1;
    for (int i = 1; i <= n; i++) {
      if (i == next_sq * next_sq) {
        squares.push_back(next_sq * next_sq);
        next_sq++;
        dp[i] = 1;
        continue;
      }
      dp[i] = 100000000;
      for (auto& sq : squares) {
        dp[i] = std::min(dp[i], 1 + dp[i - sq]);
      }
    }
    return dp[n];
  }
};
}  // namespace

using int64 = long long;

void solve(int n) {
  Solution sol;
  int result = sol.numSquares(n);
  std::cout << n << " | " << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(1);
  solve(12);
  solve(13);
  solve(25);
  return 0;
}
