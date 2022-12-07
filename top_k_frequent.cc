#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (auto num : nums) {
      freq[num]++;
    }
    std::multimap<int, int> inverted;
    for (auto it = freq.begin(); it != freq.end(); it++) {
      inverted.insert(std::make_pair(it->second, it->first));
      if (inverted.size() > k) {
        inverted.erase(inverted.begin());
      }
    }
    std::vector<int> result;
    for (auto it = inverted.rbegin(); it != inverted.rend(); it++) {
      result.push_back(it->second);
      if (result.size() == k) {
        break;
      }
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<int> nums, int k) {
  Solution sol;
  auto result = sol.topKFrequent(nums, k);
  std::cout << "[";
  for (uint i = 0; i < nums.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << nums[i];
  }
  std::cout << "] | " << k << " | [";
  for (uint i = 0; i < result.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << result[i];
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{1, 1, 1, 2, 2, 3}, 2);
  solve(std::vector<int>{1}, 1);
  solve(std::vector<int>{1, 2}, 2);
  return 0;
}
