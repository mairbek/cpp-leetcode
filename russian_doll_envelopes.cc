#include <iostream>
#include <vector>

// https://leetcode.com/problems/falling-squares/description/
namespace {
class Solution {
 public:
  int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
    std::sort(envelopes.begin(), envelopes.end(),
              [&](std::vector<int>& a, std::vector<int>& b) {
                if (a[0] == b[0]) {
                  return a[1] > b[1];
                }
                return a[0] < b[0];
              });

    if (envelopes.size() == 0) {
      return 0;
    }
    std::vector<int> tails;
    for (int i = 0; i < envelopes.size(); i++) {
      int h = envelopes[i][1];
      auto it = std::lower_bound(tails.begin(), tails.end(), h);
      if (it == tails.end()) {
        tails.push_back(h);
      } else {
        *it = h;
      }
    }
    return tails.size();
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> s) {
  Solution sol;
  int result = sol.maxEnvelopes(s);
  std::cout << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{5, 4}, {6, 4}, {6, 7}, {2, 3}});
  solve(std::vector<std::vector<int>>{{1, 1}, {1, 1}, {1, 1}});
  return 0;
}
