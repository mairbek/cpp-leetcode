#include <algorithm>
#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> tails;
    for (int i = 0; i < nums.size(); i++) {
      auto it = std::lower_bound(tails.begin(), tails.end(), nums[i]);
      if (it == tails.end()) {
        tails.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return tails.size();
  }
};
}  // namespace

void solve(std::vector<int> nums) {
  Solution sol;
  auto result = sol.lengthOfLIS(nums);
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
  solve(std::vector<int>{10, 9, 2, 5, 3, 7, 101, 18});
  solve(std::vector<int>{0, 1, 0, 3, 2, 3});
  solve(std::vector<int>{7, 7, 7, 7, 7, 7, 7});
  return 0;
}
