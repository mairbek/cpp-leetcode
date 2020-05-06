#include <iostream>
#include <stack>

// https://leetcode.com/problems/valid-parentheses/submissions/
// simple stack
namespace {
class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> st;
    for (int i = 0; i < s.size(); i++) {
    if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
      st.push(s[i]);
        continue;
      }
      if (st.empty()) {
        return false;
      }
      char top = st.top();
      st.pop();
      if (s[i] == ')' && top != '(') {
        return false;
      }
      if (s[i] == '}' && top != '{') {
        return false;
      }
      if (s[i] == ']' && top != '[') {
        return false;
      }
    }
    return st.empty();
  }
};
} // namespace

void solve(std::string s) {
  Solution sol;
  int result = sol.isValid(s);

  std::cout << s << " " << result << std::endl;
}
int main(int argc, const char** argv) {
  solve("((()))");
  solve("(((");
  solve("[({})]");
  solve("[({)]}");
  return 0;
}
