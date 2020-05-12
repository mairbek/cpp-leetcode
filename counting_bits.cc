#include <iostream>
#include <vector>

// https://leetcode.com/problems/counting-bits/
// DP O(N) time and memory. cool trick to track power of 2.
namespace {
class Solution {
 public:
  std::vector<int> countBits(int num) {
    std::vector<int> result;
    result.push_back(0);
    int pow2 = 0;
    for (int i = 1; i <= num; i++) {
      if ((i & (i - 1)) == 0) {
        pow2 = i;
        result.push_back(1);
      } else {
        int rem = i - pow2;
        result.push_back(1 + result[rem]);
      }
    }
    return result;
  }
};
}  // namespace

void solve(int n) {
  Solution sol;
  std::vector<int> result = sol.countBits(n);

  std::cout << n << " | ";
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
}
int main(int argc, const char** argv) {
  solve(2);
  solve(5);
  return 0;
}
