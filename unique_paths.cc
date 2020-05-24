#include <climits>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/unique-paths/
// DP O(n*m) time O(n*m) space.
namespace {
class Solution {
public:
    int uniquePaths(int m, int n) {
      if (m == 0 || n == 0) {
        return 0;
      }

      int dp[m][n];

      for (int i = 0; i <m; i++) {
        dp[i][0] = 1;
      }
      for (int j = 0; j <n; j++) {
        dp[0][j] = 1;
      }

      for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }

      return dp[m-1][n-1];      
    }
};
}  // namespace

void solve(int m, int n) {
  Solution sol;
  int result = sol.uniquePaths(m, n);
  std::cout << m << " " << n << " | " << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(0, 0);
  solve(10, 0);
  solve(0, 50);
  solve(1, 1);
  solve(10, 1);
  solve(1, 50);
  solve(3, 2);
  solve(7, 3);
  return 0;
}
