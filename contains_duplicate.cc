#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

namespace {
class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> visited;
    for (uint i = 0; i < nums.size(); i++) {
      if (visited.count(nums[i]) > 0) {
          return true;
      }
      visited.insert(nums[i]);
    }
    return false;
  }
};
}  // namespace

void solve(std::vector<int> prices) {
  Solution sol;
  bool result = sol.containsDuplicate(prices);
  std::cout << "[";
  for (uint i = 0; i < prices.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << prices[i];
  }
  std::cout << "] " << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<int>{1, 2, 3, 1});
  solve(std::vector<int>{1, 2, 3, 4});
  solve(std::vector<int>{1, 1, 1, 3, 3, 4, 3, 2, 4, 2});
  return 0;
}
