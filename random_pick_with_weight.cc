#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  Solution(std::vector<int>& w) {
    total_ = 0;
    for (int i = 0; i < w.size(); i++) {
      total_ += w[i];
      prefix_sum_.push_back(total_);
    }
  }

  int pickIndex() {
    int wi = rand() % total_;
    int l = 0;
    int r = prefix_sum_.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (wi < prefix_sum_[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }

 private:
  std::vector<int> prefix_sum_;
  int total_;
};
}  // namespace

void solve(std::vector<int> nums, int k) {
  Solution sol(nums);
  for (int i = 0; i < k; i++) {
    // std::cout << sol.pickIndex() << " ";
    sol.pickIndex();
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  // solve(std::vector<int>{1}, 1);
  // solve(std::vector<int>{1, 3}, 5);
  solve(std::vector<int>{3, 14, 1, 7}, 10);
  return 0;
}
