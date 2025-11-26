#include <iostream>
#include <vector>

// https://leetcode.com/problems/maximal-square/submissions/
// DP and optimized space
namespace {
class Solution {
 public:
  int maximalSquare(std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) {
      return 0;
    }
    int m = matrix[0].size();

    std::vector<int> dp(m + 1);
    for (int j = 0; j <= m; j++) {
      dp[j] = 0;
    }
    int max_area = 0;
    for (int i = 0; i < n; i++) {
      int prev = 0;
      for (int j = 0; j < m; j++) {
        int temp = dp[j + 1];
        if (matrix[i][j] == '0') {
          dp[j + 1] = 0;
        } else {
          dp[j + 1] = 1 + std::min(dp[j], std::min(dp[j + 1], prev));
          max_area = std::max(dp[j + 1], max_area);
        }
        prev = temp;
      }
    }

    return max_area * max_area;
  }

  int full_table(std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();
    if (n == 0) {
      return 0;
    }
    int m = matrix[0].size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
      dp[0][j] = 0;
    }
    int max_area = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '0') {
          dp[i + 1][j + 1] = 0;
        } else {
          dp[i + 1][j + 1] =
              1 + std::min(dp[i][j + 1], std::min(dp[i + 1][j], dp[i][j]));
          max_area = std::max(dp[i + 1][j + 1], max_area);
        }
      }
    }
    return max_area * max_area;
  }
};
}  // namespace

void solve(std::vector<std::vector<char>> s) {
  Solution sol;
  auto result = sol.maximalSquare(s);

  std::cout << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<char>>{{'1', '0', '1', '0', '0'},
                                       {'1', '0', '1', '1', '1'},
                                       {'1', '1', '1', '1', '1'},
                                       {'1', '0', '0', '1', '0'}});
  return 0;
}
