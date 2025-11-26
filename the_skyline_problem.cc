#include <iostream>
#include <set>
#include <vector>

// https://leetcode.com/problems/the-skyline-problem/
namespace {

class Solution {
 public:
  std::vector<std::vector<int>> getSkyline(
      std::vector<std::vector<int>> const& buildings) {
    std::vector<std::tuple<int, int, int>> events;
    for (int i = 0; i < buildings.size(); i++) {
      events.emplace_back(buildings[i][0], -1, buildings[i][2]);
      events.emplace_back(buildings[i][1], 1, buildings[i][2]);
    }

    std::sort(events.begin(), events.end());
    std::multiset<int> heights;
    std::vector<std::vector<int>> result;
    for (auto ev : events) {
      int topHeight = heights.empty() ? 0 : *(heights.rbegin());
      if (std::get<1>(ev) == -1) {
        heights.emplace(std::get<2>(ev));
      } else {
        heights.erase(heights.find(std::get<2>(ev)));
      }
      int newHeight = heights.empty() ? 0 : *(heights.rbegin());
      if (newHeight != topHeight) {
        if (!result.empty() && std::get<0>(ev) == result.back()[0]) {
          result.back()[1] = newHeight;
        } else {
          result.push_back({std::get<0>(ev), newHeight});
        }
      }
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> const& buildings) {
  Solution sol;
  auto result = sol.getSkyline(buildings);

  std::cout << "[";
  for (auto& v : result) {
    std::cout << "[";
    for (auto& x : v) {
      std::cout << x << " ";
    }
    std::cout << "] ";
  }
  std::cout << "]";
  std::cout << std::endl;
}
int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{
      {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}});
  solve(std::vector<std::vector<int>>{{0, 2, 3}, {2, 5, 3}});
  solve(std::vector<std::vector<int>>{{0, 2, 3}, {2, 5, 3}});
  solve(std::vector<std::vector<int>>{{0, 10, 3}, {2, 5, 3}, {7, 9, 3}});
  solve(std::vector<std::vector<int>>{{0, 2, 3}});
  solve(std::vector<std::vector<int>>{{1, 2, 1},
                                      {
                                          1,
                                          2,
                                          2,
                                      },
                                      {1, 2, 3}});

  return 0;
}
