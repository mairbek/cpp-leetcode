#include <iostream>

// https://leetcode.com/problems/first-bad-version/
// simple binary search.
namespace {
class Solution {
 public:
  bool isBadVersion(int n) { return n >= 3; }

  int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l <= r) {
      int m = (l / 2) + (r / 2) + ((l % 2 + r % 2) / 2);
      if (isBadVersion(m)) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
}  // namespace

void solve(int n) {
  Solution sol;
  int result = sol.firstBadVersion(n);

  std::cout << n << " " << result << std::endl;
}
int main(int argc, char const** argv) {
  solve(5);
  return 0;
}
