#include <iostream>
#include <unordered_map>
#include <vector>

namespace {
// https://leetcode.com/problems/basic-calculator
// Shunting yard
class Solution {
 public:
  void eval(std::vector<int>* nums, std::vector<std::string>* ops) {
    std::string top = ops->back();
    ops->pop_back();
    int a = nums->back();
    nums->pop_back();
    int b = nums->back();
    nums->pop_back();
    if (top == "+") {
      nums->push_back(a + b);
    } else if (top == "-") {
      nums->push_back(b - a);
    } else if (top == "*") {
      nums->push_back(a * b);
    } else if (top == "/") {
      nums->push_back(b / a);
    }
  }

  void pprint(std::vector<int>& nums, std::vector<std::string>& ops) {
    for (auto& k : nums) {
      std::cout << k << " ";
    }
    std::cout << std::endl;
    for (auto& k : ops) {
      std::cout << k << " ";
    }
    std::cout << std::endl;
  }

  int calculate(std::string s) {
    std::vector<std::string> tokens = tokenize(s);

    std::vector<int> nums;
    std::vector<std::string> ops;

    for (auto& token : tokens) {
      if (token == "(") {
        ops.push_back(token);
      } else if (token == ")") {
        while (true) {
          std::string top = ops.back();
          if (top == "(") {
            ops.pop_back();
            break;
          }
          if (nums.size() >= 2) {
            eval(&nums, &ops);
          }
        }
      } else if (token == "+" || token == "-" || token == "*" || token == "/") {
       while (!ops.empty()) {
          std::string top = ops.back();
          if (precedence(top) < precedence(token)) {
            break;
          }
          eval(&nums, &ops);
        }
        ops.push_back(token);
      } else {
        nums.push_back(std::stoi(token));
      }
    }
    while (!ops.empty()) {
      eval(&nums, &ops);
    }
    return nums.back();
  }

  int precedence(std::string token) {
    if (token == "(") {
      return 0;
    }
    if (token == "+" || token == "-") {
      return 1;
    }
    // token == "*" || token == "/"
    return 2;
  }

  std::vector<std::string> tokenize(std::string& s) {
    std::vector<std::string> result;
    std::string token = "";

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ') {
        continue;
      }
      if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' ||
          s[i] == '(' || s[i] == ')') {
        if (token != "") {
          result.push_back(token);
        }
        token = "";
        std::string op(1, s[i]);
        result.push_back(op);
      } else {
        token += s[i];
      }
    }
    if (token != "") {
      result.push_back(token);
    }
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

int main(int argc, const char** argv) {
  solve("1+1");
  solve("(1+1)*2");
  solve("(1)");
  solve("1-(5)");
  solve("2-4-(8+2-6+(8+4-(1)+8-10))");
  solve("2 -(8+(8+4-(1)+8-10))");
  return 0;
}
