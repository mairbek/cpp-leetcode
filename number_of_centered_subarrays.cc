#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
class Solution {
 public:
  int centeredSubarrays(std::vector<int>& nums) {
    std::vector<int> prefix(nums.size() + 1);
    std::unordered_map<int, std::vector<int>> positions;
    for (size_t i = 0; i < nums.size(); i++) {
        prefix[i+1] = prefix[i] + nums[i];
        positions[nums[i]].push_back(i);
    }
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = i; j < nums.size(); j++) {
            int sum = prefix[j + 1] - prefix[i];
            if (!positions.contains(sum)) {
                continue;
            }
            auto it = std::lower_bound(positions[sum].begin(), positions[sum].end(), i);
            if (it == positions[sum].end() || *it > j) {
                continue;
            }
            result++;
        }
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<int> nums, int expected) {
  Solution sol;
  int result = sol.centeredSubarrays(nums);
  std::cout << "[";
  for (size_t i = 0; i < nums.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << nums[i];
  }
  std::cout << "] => " << result << " (expected: " << expected << ")"
            << std::endl;
}

int main(int argc, char const** argv) {
  solve({-1, 1, 0}, 5);
  solve({2, -3}, 2);
  return 0;
}
