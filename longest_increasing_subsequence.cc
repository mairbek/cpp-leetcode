#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace {
class Solution {
 public:
  int lengthOfLIS(std::vector<int>& nums) { 
    if (nums.size() == 0) {
      return 0;
    }
    std::vector<int> lis(nums.size(), 0);
    lis[0] = 1;
    int result = 1;
    for (int i = 1; i < nums.size(); i++) {
      int max = 0;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          if (max < lis[j]) {
            max = lis[j];
          }
        }
      }
      lis[i] = 1 + max;
      if (result < lis[i]) {
        result = lis[i];
      }
    }
    return result; 
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
