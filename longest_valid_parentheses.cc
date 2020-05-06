#include <iostream>
#include <stack>

// https://leetcode.com/problems/longest-valid-parentheses/
// DP solution
namespace {
class Solution {
 public:
  int longestValidParentheses(std::string s) {
    return faster(s);
  }

  int faster(std::string s) {
    int n = s.size();
    int max_valid = 0;
    int open = 0;
    int closed = 0;
    std::stack<int> st;
    std::stack<std::pair<int, int>> ranges;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        open++;
        st.push(i);
      } else {
        if (closed == open) {
          continue;
        }
        closed++;
        int k = st.top();
        if (ranges.empty()) {
          ranges.push({k, i});
        } else {
          auto left = ranges.top();
          while (true) {
            if (k > left.first) {
              break;
            }
            ranges.pop();
            if (ranges.empty()) {
              break;
            }
            left = ranges.top();
          }
          if (!ranges.empty() && left.second == (k - 1)) {
            ranges.push({left.first, i});
          } else {
            ranges.push({k, i});
          }
        }
        st.pop();
      }
    }

    while (!ranges.empty()) {
      auto range = ranges.top();
      max_valid = std::max(max_valid, range.second - range.first + 1);
      ranges.pop();
    }
    return max_valid;
  }

  int brute_force(std::string s) {
    int n = s.size();
    int max_valid = 0;
    for (int i = 0; i < n; i++) {
      int open = 0;
      int closed = 0;
      std::stack<int> st;
      int l = 1000000000;
      int r = 0;
      int valid = 0;
      for (int j = i; j < n; j++) {
        if (s[j] == '(') {
          open++;
          st.push(j);
        } else {
          if (closed == open) {
            break;
          }
          closed++;
          if (st.top() < l) {
            l = st.top();
          }
          st.pop();
          r = j;
          if (st.empty()) {
            valid += r - l + 1;
            l = 1000000000;
            r = 0;
          }
        }
      }
      if (valid > max_valid) {
        max_valid = valid;
      }
     }

    return max_valid;
  }
};
} // namespace

void solve(std::string s) {
  Solution sol;
  int result = sol.longestValidParentheses(s);

  std::cout << s << " " << result << std::endl;
}
int main(int argc, const char** argv) {
  solve("(");
  solve("(()");
  solve(")()())");
  solve("((()))");
  solve(")(((((()())()()))()(()))(");
  solve("()(()");
  solve("()(())");
  solve(")()(((())))(");
  return 0;
}
