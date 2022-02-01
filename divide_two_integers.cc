#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace {
// https://leetcode.com/problems/word-break/
// DP O(N * M)
class Solution {
 
 public:
  int divide(int dividend, int divisor) {
    int sign = 1;
    if (divisor < 0) {
      sign = -sign;
      divisor = -divisor;
    }
    if (dividend < 0) {
      sign = -sign;
      dividend = -dividend;
    }
    int result = 0;
    int acc = 0;
    while (true) {
      acc += divisor;
      if (acc > dividend) {
        break;
      }
      result++;
    }
    if (sign < 0) {
      return -result;
    }
    return result;
  }

};
}  // namespace

using int64 = long long;

void solve(int dividend, int divisor) {
  Solution sol;
  int result = sol.divide(dividend, divisor);
  std::cout << dividend << "/" << divisor << "=" << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(10, 3);
  solve(7, -3);
  solve(0, 3);
  return 0;
}
