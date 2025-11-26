#include <algorithm>
#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  int rob(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n + 2, 0);
    for (int i = 0; i < n; i++) {
      dp[i + 2] = std::max(dp[i + 1], dp[i] + nums[i]);
    }
    return dp[n + 1];
  }
};
}  // namespace

void solve(std::vector<int> nums) {
  Solution sol;
  auto result = sol.rob(nums);
  std::cout << "[";
  for (uint i = 0; i < nums.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << nums[i];
  }
  std::cout << "] " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{1, 2, 3, 1});
  solve(std::vector<int>{2, 7, 9, 3, 1});
  solve(std::vector<int>{});
  solve(std::vector<int>{10});
  return 0;
}
