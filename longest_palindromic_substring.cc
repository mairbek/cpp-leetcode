#include <iostream>
#include <stack>

// https://leetcode.com/problems/valid-palindrome
// Two pointers
namespace {
class Solution {
 public:
  std::string longestPalindrome(std::string s) {
    return expand_center(s);
  }

  int check_valid(std::string& s, int i, int j, int* ll, int* rr) {
    if (s[i] != s[j]) {
      return 0;
    }
    int n = s.length();
    int l = i, r = j;
    while(l >= 0 && r <= n - 1) {
      if (s[l] != s[r]) {
        break;
      }
      *ll = l;
      *rr = r;
      l--;
      r++;
    }
    return r - l + 1;
  }

  std::string expand_center(std::string s) {
    int n = s.length();
    int max_len = 0;
    int ma, mb = 0;
    for (int i = 0; i < n; i++) {
      int l, r;
      int nn = check_valid(s, i, i, &l, &r);
      if (nn > max_len) {
        max_len = nn;
        ma = l;
        mb = r;
      }
      if (i < (n-1)) {
        int nn = check_valid(s, i, i+1, &l, &r);
        if (nn > max_len) {
          max_len = nn;
          ma = l;
          mb = r;
        }
      }
    }
    return s.substr(ma, mb - ma + 1);
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
