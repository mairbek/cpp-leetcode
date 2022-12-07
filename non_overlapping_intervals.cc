#include <iostream>
#include <vector>

// https://leetcode.com/problems/non-overlapping-intervals/
// Greedy algorithm for an activity selection problem.
// More info
// http://web.stanford.edu/class/archive/cs/cs161/cs161.1182/Lectures/Lecture14/Lecture14-compressed.pdf
// The idea is to compute the maximum number of non-overlapping intervals and
// subtract it from the total number of intervals.
namespace {
class Solution {
 public:
  int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    if (intervals.size() == 0) return 0;
    // sort by end time
    std::sort(intervals.begin(), intervals.end(),
              [](std::vector<int> const& a, std::vector<int> const& b) {
                return a[1] < b[1];
              });
    int selection = 1;
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] >= end) {
        end = intervals[i][1];
        selection++;
      }
    }
    return intervals.size() - selection;
  };
};
}  // namespace

void solve(std::vector<std::vector<int>> intervals) {
  Solution sol;
  auto result = sol.eraseOverlapIntervals(intervals);
  std::cout << result << std::endl;
}
int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{1, 2}, {2, 3}, {3, 4}, {1, 3}});
  solve(std::vector<std::vector<int>>{{1, 2}, {1, 2}, {1, 2}});
  solve(std::vector<std::vector<int>>{{1, 2}, {2, 3}});
  solve(std::vector<std::vector<int>>{});

  solve(std::vector<std::vector<int>>{{1, 100}, {11, 22}, {1, 11}, {2, 12}});
  return 0;
}
