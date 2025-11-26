#include <iostream>

namespace {
class Solution {
 public:
  int getSum(int a, int b) {
    // XOR + AND shift
    while (b != 0) {
      uint32_t c = uint32_t(a & b);
      a = a ^ b;
      b = c << 1;
    }
    return a;
  }
};
}  // namespace

void solve(int a, int b) {
  Solution sol;
  int result = sol.getSum(a, b);
  std::cout << a << " " << b << " " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(1, 2);
  solve(2, 3);
  solve(0, 0);
  solve(1, 1);
  solve(-1, 1);
  return 0;
}
