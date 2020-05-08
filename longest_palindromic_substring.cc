#include <iostream>
#include <stack>

// https://leetcode.com/problems/valid-palindrome
// Two pointers
namespace {
class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    return brute_force(s);
  }

  std::string brute_force(std::string s) {
    int n = s.length();
    int max_len = 0;
    int ma, mb = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int l = i, r = j;
        bool is_valid = true;
        while (l <= r) {
          if (s[l] != s[r]) {
            is_valid = false;
            break;
          }
          l++;
          r--;
        }
        if (is_valid) {
          int nn = j - i + 1;
          if (nn > max_len) {
            ma = i;
            mb = j;
            max_len = nn;
          }
        }
      }
    }
    std::cout << ma << " " << mb << std::endl;
    return s.substr(ma, mb - ma + 1);
  }
};
} // namespace

void solve(std::string s) {
  Solution sol;
  auto result = sol.longestPalindrome(s);

  std::cout << s << " " << result << std::endl;
}
int main(int argc, const char** argv) {
  solve("babad");
  solve("cbbd");
  return 0;
}
