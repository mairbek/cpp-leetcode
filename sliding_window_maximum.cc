#include <iostream>
#include <set>
#include <vector>

namespace {

class Solution {
 public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::multiset<int> w;

    int t = 0;
    for (int i = 0; i < nums.size(); i++) {
      w.insert(nums[i]);
      if (w.size() > k) {
        auto it = w.find(nums[t++]);
        w.erase(it);
      }
      if (w.size() == k) {
        result.push_back(*w.rbegin());
      }
    }
    return result;
  }
};
}  // namespace

using int64 = long long;

void solve(std::vector<int> s, int k) {
  Solution sol;
  auto result = sol.maxSlidingWindow(s, k);
  for (int i = 0; i < s.size(); i++) {
    std::cout << s[i] << " ";
  }
  std::cout << "| " << k << " > ";
  for (auto rr : result) {
    std::cout << rr << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{1, 3, -1, -3, 5, 3, 6, 7}, 3);
  solve(std::vector<int>{7, 2, 4}, 2);
  solve(std::vector<int>{-7, -8, 7, 5, 7, 1, 6, 0}, 4);
  return 0;
}
