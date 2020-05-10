#include <iostream>
#include <vector>

namespace {
// https://leetcode.com/problems/climbing-stairs/
// easy fibonacci
class Solution {
 public:
  int fib(int n) {
    int a = 1, b = 1;
    for (int i = 1; i < n; i++) {
      int nb = a + b;
      a = b;
      b = nb;
    }
    return b;
  }
  int climbStairs(int n) { return fib(n); }
};
}  // namespace

using int64 = long long;

void solve(int n) {
  Solution sol;
  int result = sol.climbStairs(n);
  std::cout << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(2);
  solve(3);
  solve(4);
  solve(5);
  return 0;
}
