#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  Solution(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      items_[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    const auto& v = items_[target];
    int r = rand() % v.size();
    return v[r];
  }

 private:
  std::unordered_map<int, std::vector<int>> items_;
};
}  // namespace

void solve(std::vector<int> nums, std::vector<int> k) {
  Solution sol(nums);
  for (int i = 0; i < k.size(); i++) {
    std::cout << sol.pick(k[i]) << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{1, 2, 3, 3, 3}, std::vector<int>{3, 1, 3});
  return 0;
}
