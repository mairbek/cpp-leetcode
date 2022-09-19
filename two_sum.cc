#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> prev;
        std::vector<int> result;
        for (uint i = 0; i < nums.size(); i++) {
            int k = target - nums[i];
            auto it = prev.find(k);
            if (it != prev.end()) {
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
            prev[nums[i]] = i;
        }
        return result;
    }
};
}  // namespace

void solve(std::vector<int> nums, int target) {
  Solution sol;
  auto result = sol.twoSum(nums, target);
  std::cout << "[";
  for (uint i = 0; i < nums.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << nums[i];
  }
  std::cout << "] | " << target << " | [";
  for (uint i = 0; i < result.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << result[i];
  }
  std::cout << "]" << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<int>{2, 7, 11, 15}, 9);
  solve(std::vector<int>{3, 2, 4}, 6);
  solve(std::vector<int>{3, 3}, 6);
  return 0;
}
