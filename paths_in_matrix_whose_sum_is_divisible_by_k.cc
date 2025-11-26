#include <iostream>
#include <vector>

// a + b = c mod n
// b = (n + c - a) mod n
// 5, 2, 4
// 3, 0, 5
// 0, 7, 2

// dp[0][0][2] = 1;
// dp[0][1][0] += dp[0][0][1]  # 1 = (3 + 0 - 2) % 3
// dp[0][1][1] += dp[0][0][2]  # 2 = (3 + 1 - 2) % 3
// dp[0][1][2] += dp[0][0][0]  # 0 = (3 + 2 - 2) % 3
// (k + ki - gk)

namespace {

// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
class Solution {
 public:
  int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
    int const MOD = 1e9 + 7;
    int n = grid.size();
    int m = grid[0].size();
    std::vector<std::vector<std::vector<int>>> dp(
        n, std::vector<std::vector<int>>(m, std::vector<int>(k + 1, 0)));
    dp[0][0][grid[0][0] % k] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int gk = grid[i][j] % k;
        if (i == 0 && j == 0) {
          dp[i][j][gk] = 1;
          continue;
        }
        for (int ki = 0; ki < k; ki++) {
          if (i > 0) {
            // std::cout << "dp[" << i-1 << "[" <<j <<"][" << (k + ki - gk) % k
            // << "]" << std::endl;
            dp[i][j][ki] =
                (dp[i][j][ki] + dp[i - 1][j][(k + ki - gk) % k]) % MOD;
          }
          if (j > 0) {
            dp[i][j][ki] =
                (dp[i][j][ki] + dp[i][j - 1][(k + ki - gk) % k]) % MOD;
          }
        }
      }
    }
    return dp[n - 1][m - 1][0];
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> grid, int k) {
  Solution sol;
  int result = sol.numberOfPaths(grid, k);
  std::cout << "Grid: ";
  for (auto const& row : grid) {
    std::cout << "[";
    for (size_t i = 0; i < row.size(); i++) {
      if (i > 0) std::cout << ",";
      std::cout << row[i];
    }
    std::cout << "] ";
  }
  std::cout << "k=" << k << " => " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{5, 2, 4}, {3, 0, 5}, {0, 7, 2}}, 3);
  solve(std::vector<std::vector<int>>{{7, 3, 4, 9}, {2, 3, 6, 2}, {2, 3, 7, 0}},
        1);
  solve(std::vector<std::vector<int>>{{0}, {0}}, 5);
  solve(std::vector<std::vector<int>>{{0}}, 5);
  return 0;
}
