#include <iostream>

namespace {
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int result = 0;
    while (n > 0) {
      n = n & (n - 1);
      result++;
    }
    return result;
  }
};
}  // namespace

void solve(uint32_t n) {
  Solution sol;
  int result = sol.hammingWeight(n);

  std::cout << n << " " << result << std::endl;
}
int main(int argc, char const** argv) {
  solve(0b00000000000000000000000000000000);
  solve(0b00000000000000000000000000001011);
  solve(0b00000000000000000000000010000000);
  solve(0b11111111111111111111111111111101);
  return 0;
}
