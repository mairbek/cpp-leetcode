#include <iostream>
#include <vector>

// https://leetcode.com/problems/insert-interval/
namespace {
class Solution {
 public:
  std::vector<std::vector<int>> insert(
      std::vector<std::vector<int>> const& intervals,
      std::vector<int> const& newIntervalConst) {
    std::vector<std::vector<int>> result;

    std::vector<std::vector<int>> st;
    st.push_back(newIntervalConst);

    int i = 0;
    for (; i < intervals.size(); i++) {
      if (intervals[i][1] < st[0][0]) {
        result.push_back(intervals[i]);
      } else if (intervals[i][0] > st[0][1]) {
        break;
      } else {
        st[0][0] = std::min(st[0][0], intervals[i][0]);
        st[0][1] = std::max(st[0][1], intervals[i][1]);
      }
    }
    for (int j = 0; j < st.size(); j++) {
      result.push_back(st[j]);
    }
    for (int j = i; j < intervals.size(); j++) {
      result.push_back(intervals[j]);
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> const& intervals,
           std::vector<int> const& newInterval) {
  Solution sol;
  auto result = sol.insert(intervals, newInterval);

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
  solve(std::vector<std::vector<int>>{}, std::vector<int>{5, 9});
  solve(std::vector<std::vector<int>>{{1, 3}, {6, 9}}, std::vector<int>{2, 5});
  solve(std::vector<std::vector<int>>{{1, 3}}, std::vector<int>{5, 9});
  solve(std::vector<std::vector<int>>{{1, 20}}, std::vector<int>{5, 9});
  return 0;
}
