#include <algorithm>
#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    std::vector<int> dp;
    dp.push_back(nums[0]);
    for (uint i = 1; i < nums.size(); i++) {
      int s = std::max(dp[i - 1] + nums[i], nums[i]);
      dp.push_back(s);
    }
    return *std::max_element(dp.begin(), dp.end());
  }
};
}  // namespace

void solve(std::vector<int> nums) {
  Solution sol;
  int result = sol.maxSubArray(nums);
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
  solve(std::vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4});
  solve(std::vector<int>{1});
  solve(std::vector<int>{5, 4, -1, 7, 8});
  return 0;
}
