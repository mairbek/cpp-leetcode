#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace {
class Solution {
 public:
  int rob(std::vector<int>& nums) { 
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
      return std::max(rob_dp(std::vector<int>(nums.begin(), nums.end() - 1)),
                    rob_dp(std::vector<int>(nums.begin() + 1, nums.end())));
  }

  int rob_dp(std::vector<int> nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }
    if (nums.size() == 2) {
      return std::max(nums[0], nums[1]);
    }
    std::vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    for (uint i = 2; i < nums.size(); i++) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
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
  solve(std::vector<int>{2, 3, 2});
  solve(std::vector<int>{1, 2, 3, 1});
  solve(std::vector<int>{1, 2, 3});
  return 0;
}
