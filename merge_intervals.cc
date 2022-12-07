#include <iostream>
#include <vector>

// https://leetcode.com/problems/merge-intervals/
namespace {
class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](std::vector<int> const& a, std::vector<int> const& b) {
                return a[0] < b[0];
              });
    std::vector<std::vector<int>> result;
    if (intervals.size() > 0) {
      result.push_back(intervals[0]);
    }
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] > result.back()[1]) {
        result.push_back(intervals[i]);
      } else {
        result.back()[1] = std::max(result.back()[1], intervals[i][1]);
      }
    }
    return result;
  };
};
}  // namespace

void solve(std::vector<std::vector<int>> intervals) {
  Solution sol;
  auto result = sol.merge(intervals);

  for (auto& v : result) {
    std::cout << "[";
    for (auto& x : v) {
      std::cout << x << " ";
    }
    std::cout << "] ";
  }
  std::cout << std::endl;
}
int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{1, 3}, {2, 6}, {8, 10}, {15, 18}});
  solve(std::vector<std::vector<int>>{{1, 4}, {4, 5}});
  solve(std::vector<std::vector<int>>{{1, 5}});
  solve(std::vector<std::vector<int>>{{1, 4}, {0, 4}});
  solve(std::vector<std::vector<int>>{});
  return 0;
}
