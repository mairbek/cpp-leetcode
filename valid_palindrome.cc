#include <iostream>
#include <stack>

// https://leetcode.com/problems/valid-palindrome
// Two pointers
namespace {
class Solution {
 public:
  bool isPalindrome(std::string s) {
    int l = 0;
    int r = s.length() - 1;
    while (l <= r) {
      if (!isalnum(s[l])) {
        l++;
        continue;
      }
      if (!isalnum(s[r])) {
        r--;
        continue;
      }
      if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
};
} // namespace

void solve(std::string s) {
  Solution sol;
  bool result = sol.isPalindrome(s);

  std::cout << s << " " << result << std::endl;
}
int main(int argc, const char** argv) {
  solve("A man, a plan, a canal: Panama");
  solve("race a car");
  solve("aba");
  solve("a");
  return 0;
}
