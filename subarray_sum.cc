#include <iostream>
#include <unordered_map>
#include <vector>

namespace {

// https://leetcode.com/problems/subarray-sum-equals-k
// O(N) solution
class Solution {
 public:
  int subarraySum(std::vector<int>& nums, int k) {
    int n = nums.size();

    std::unordered_map<int, int> cache;

    cache[0] = 1;
    int sum = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      auto it = cache.find(sum - k);
      if (it != cache.end()) {
        result += it->second;
      }
      cache[sum]++;
    }
    return result;
  }
};
}  // namespace

using int64 = long long;

void solve(std::vector<int> s, int k) {
  Solution sol;
  int result = sol.subarraySum(s, k);
  for (int i = 0; i < s.size(); i++) {
    std::cout << s[i] << " ";
  }
  std::cout << "| " << k << " " << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<int>{1, 1, 1, 1}, 2);
  return 0;
}
