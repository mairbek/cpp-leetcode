#include <iostream>
#include <vector>

namespace {

// https://leetcode.com/problems/basic-calculator-ii/
// Shunting yard
class Solution {
 public:
  int calculate(std::string s) {
    std::vector<std::string> tokens = tokenize(s);

    std::vector<int> nums;
    std::vector<std::string> ops;

    for (auto& token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        while (!ops.empty()) {
          std::string top = ops.back();
          if (precedence(top) >= precedence(token)) {
            ops.pop_back();
            int a = nums.back();
            nums.pop_back();
            int b = nums.back();
            nums.pop_back();
            if (top == "+") {
              nums.push_back(a + b);
            } else if (top == "-") {
              nums.push_back(b - a);
            } else if (top == "*") {
              nums.push_back(a * b);
            } else if (top == "/") {
              nums.push_back(b / a);
            } else {
              return -1;
            }
          } else {
            break;
          }
        }
        ops.push_back(token);
      } else {
        nums.push_back(std::stoi(token));
      }
    }
    while (!ops.empty()) {
      std::string top = ops.back();
      ops.pop_back();
      int a = nums.back();
      nums.pop_back();
      int b = nums.back();
      nums.pop_back();
      if (top == "+") {
        nums.push_back(a + b);
      }
      if (top == "-") {
        nums.push_back(b - a);
      }
      if (top == "*") {
        nums.push_back(a * b);
      }
      if (top == "/") {
        nums.push_back(b / a);
      }
    }
    return nums.back();
  }

  int precedence(std::string token) {
    if (token == "+" || token == "-") {
      return 1;
    }
    return 2;
  }

  std::vector<std::string> tokenize(std::string& s) {
    std::vector<std::string> result;
    std::string token = "";

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        continue;
      }
      if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
        result.push_back(token);
        token = "";
        std::string op(1, s[i]);
        result.push_back(op);
      } else {
        token += s[i];
      }
    }
    result.push_back(token);
    return result;
  }
};
}  // namespace

using int64 = long long;

void solve(std::string s) {
  Solution sol;
  int result = sol.calculate(s);
  std::cout << s << " | " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve("3+2*2");
  solve("3/2");
  solve("3+5 / 2");
  solve("1+1+1+1");
  solve("2*2*   2*2");
  return 0;
}
