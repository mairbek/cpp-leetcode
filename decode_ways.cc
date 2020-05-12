#include <iostream>
#include <unordered_map>
#include <vector>

namespace {

// https://leetcode.com/problems/decode-ways/submissions/
// DP, O(N) time O(1) memory
class Solution {
 public:
  int numDecodings(std::string s) {
    int n = s.length();
    if (n == 0) {
      return 0;
    }
    int a = 1, b = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < n; i++) {
      int c = 0;
      if (s[i] != '0') {
        c += b;
      }
      if (s[i - 1] == '1') {
        c += a;
      } else if (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6') {
        c += a;
      }
      a = b;
      b = c;
    }
    return b;
  }
};
}  // namespace

using int64 = long long;

void solve(std::string s) {
  Solution sol;
  int result = sol.numDecodings(s);
  std::cout << s << " | " << result << std::endl;
}

int main(int argc, const char** argv) {
  solve("0");
  solve("10");
  solve("17");
  solve("1223");
  return 0;
}
