#include <iostream>

namespace {

// https://leetcode.com/problems/valid-palindrome-ii/submissions/
// O(N) greedy recursive
class Solution {
 public:
  bool range(std::string& s, int l, int r, bool error) {
    if (l > r) {
      return true;
    }
    if (s[l] == s[r]) {
      return range(s, l + 1, r - 1, error);
    }
    if (!error) {
      return range(s, l + 1, r, true) || range(s, l, r - 1, true);
    }
    return false;
  }

  bool validPalindrome(std::string s) {
    return range(s, 0, s.length() - 1, false);
  }
};
}  // namespace

using int64 = long long;

void solve(std::string s) {
  Solution sol;
  bool result = sol.validPalindrome(s);
  std::cout << s << " | " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve("aba");
  solve("cbbb");
  solve("abbca");
  solve("abcd");
  return 0;
}
