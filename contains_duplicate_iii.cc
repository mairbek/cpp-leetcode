#include <iostream>
#include <set>
#include <vector>

namespace {
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff,
                                     int valueDiff) {
    std::multiset<int> window;
    for (int i = 0; i < nums.size(); i++) {
      if (i > indexDiff) {
        window.erase(window.find(nums[i - indexDiff - 1]));
      }
      int l = nums[i] - valueDiff;
      int r = nums[i] + valueDiff;
      auto lit = window.lower_bound(l);
      auto rit = window.upper_bound(r);
      if (lit != rit) {
        // not empty
        return true;
      }
      window.insert(nums[i]);
    }
    return false;
  }
};
}  // namespace

void solve(std::vector<int> nums, int indexDiff, int valueDiff) {
  Solution sol;
  bool result = sol.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);
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
  solve(std::vector<int>{1, 2, 3, 1}, 3, 0);
  solve(std::vector<int>{1, 5, 9, 1, 5, 9}, 2, 3);
  solve(std::vector<int>{5, 3, 4, 8}, 3, 0);
  solve(std::vector<int>{5, 3, 5, 8}, 3, 0);
  solve(std::vector<int>{-5, 3, -4, 8}, 3, 1);
  return 0;
}
