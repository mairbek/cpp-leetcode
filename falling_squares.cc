#include <iostream>
#include <map>
#include <vector>

// https://leetcode.com/problems/falling-squares/description/
namespace {
class Solution {
 public:
  std::vector<int> fallingSquares(std::vector<std::vector<int>>& positions) {
    int min_left = 0;
    int max_right = 100000001;
    std::map<int, std::pair<int, int>> squares;
    std::vector<int> result;

    int max_height = 0;
    for (auto& pos : positions) {
      int x = pos[0];
      int h = pos[1];
      int y = x + h;

      int l = min_left;
      int lh = -1;
      int lx = -1;
      int r = max_right;
      int rh = -1;
      int ry = -1;

      auto it = squares.lower_bound(x);
      if (it != squares.end()) {
        r = it->first;
        ry = it->second.second;
        rh = it->second.first;
      }
      if (it != squares.begin()) {
        auto pit = std::prev(it);
        l = pit->second.second;
        lh = pit->second.first;
        lx = pit->first;
      }

      int new_height = 0;
      if (x > l && y < r) {
        // no overlap
        squares[x] = std::make_pair(h, y);
        new_height = h;
      } else {
        if (l > min_left && x < l) {
          squares[lx] = std::make_pair(lh, x);
          new_height = std::max(new_height, lh);
        }
        if (r < max_right && r < y) {
          squares.erase(r);
          squares[y] = std::make_pair(rh, ry);
          new_height = std::max(new_height, rh);
        }
        new_height = h + new_height;
        squares[x] = std::make_pair(new_height, y);
      }
      max_height = std::max(max_height, new_height);
      result.push_back(max_height);
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> s) {
  Solution sol;
  auto result = sol.fallingSquares(s);

  std::cout << "[";
  for (uint i = 0; i < result.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << result[i];
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{1, 2}, {2, 3}, {6, 1}});
  solve(std::vector<std::vector<int>>{{100, 100}, {200, 100}});
  solve(std::vector<std::vector<int>>{{2, 5}, {2, 5}, {2, 5}});
  return 0;
}
