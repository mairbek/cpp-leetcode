#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> result;
    result.push_back(1);
    for (uint i = 1; i < nums.size(); i++) {
      result.push_back(nums[i - 1] * result[i - 1]);
    }
    int reverse = 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      reverse *= nums[i + 1];
      result[i] *= reverse;
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<int> nums) {
  Solution sol;
  auto result = sol.productExceptSelf(nums);
  std::cout << "[";
  for (uint i = 0; i < nums.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << nums[i];
  }
  std::cout << "] ";
  std::cout << "[";
  for (uint i = 0; i < result.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << result[i];
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{1, 2, 3, 4});
  solve(std::vector<int>{-1, 1, 0, -3, 3});
  return 0;
}
