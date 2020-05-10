#include <climits>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/triangle/
// DP O(n*m) time O(n) space.
namespace {

class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& a) {
    std::vector<int> dp{0, 0};
    int result;
    for (int i = 0; i < a.size(); i++) {
      int m = a[i].size();
      std::vector<int> newdp(m + 2, INT_MAX);
      result = INT_MAX;
      for (int j = 0; j < m; j++) {
        newdp[j + 1] = std::min(dp[j], dp[j + 1]) + a[i][j];
        result = std::min(result, newdp[j + 1]);
      }
      dp = newdp;
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> s) {
  Solution sol;
  int result = sol.minimumTotal(s);
  std::cout << "[" << std::endl;
  for (int i = 0; i < s.size(); i++) {
    std::cout << "\t[";
    for (int j = 0; j < s[i].size(); j++) {
      std::cout << s[i][j] << " ";
    }
    std::cout << "]," << std::endl;
  }
  std::cout << "]" << std::endl;
  std::cout << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<std::vector<int>>{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}});
  return 0;
}
