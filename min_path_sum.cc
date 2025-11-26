#include <iostream>
#include <vector>

namespace {

// https://leetcode.com/problems/maximal-rectangle/
// O(N**2) solution using a stack
// Similar to `rectangle_histogram.cc`.
class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[0][1] = 0;
    for (int i = 2; i <= n; i++) {
      dp[i][0] = 100000000;
    }

    for (int j = 2; j <= m; j++) {
      dp[0][j] = 100000000;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i + 1][j + 1] = std::min(dp[i][j + 1], dp[i + 1][j]);
        dp[i + 1][j + 1] += a[i][j];
      }
    }
    return dp[n][m];
  }
};
}  // namespace

using int64 = long long;

void solve(std::vector<std::vector<int>> s) {
  Solution sol;
  int result = sol.minPathSum(s);
  std::cout << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}});
  return 0;
}
