#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace {
class Solution {
 public:
  int findDuplicate(std::vector<int>& nums) { 
    int slow = nums[0];
    int fast = nums[0];
    while(true) {
        std::cout << slow << "->" << nums[slow] << " " << fast << "->" << nums[fast] << "->" << nums[nums[fast]] << " " << std::endl;
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        }
    }
    return slow;
  }

};
}  // namespace

void solve(std::vector<int> nums) {
  Solution sol;
  auto result = sol.findDuplicate(nums);
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
//   solve(std::vector<int>{1,3,4,2,2});
//   solve(std::vector<int>{3,1,3,4,2});
//   solve(std::vector<int>{3,3,3,3,3});
  solve(std::vector<int>{2,5,9,6,9,3,8,9,7,1});
  return 0;
}
