#include <iostream>
#include <vector>

namespace {

// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
// O(N) solution using a stack
class Solution {
 public:
  int largestRectangleArea(std::vector<int>& a) {
    int n = a.size();
    std::vector<int> s;

    int max_area = 0;
    for (int i = 0; i < n; i++) {
      while (s.size() > 0 && a[s.back()] >= a[i]) {
        int top = s.back();
        s.pop_back();
        int height = a[top];
        int width = s.size() == 0 ? i : i - s.back() - 1;
        max_area = std::max(max_area, width * height);
      }
      s.push_back(i);
    }

    while (s.size() > 0) {
      int top = s.back();
      s.pop_back();
      int height = a[top];
      int width = s.size() == 0 ? n : n - 1 - s.back();
      max_area = std::max(max_area, width * height);
    }

    return max_area;
  }
};
}  // namespace

using int64 = long long;

void solve(std::vector<int> s) {
  Solution sol;
  int result = sol.largestRectangleArea(s);
  std::cout << "[";
  for (size_t i = 0; i < s.size(); i++) {
    std::cout << s[i] << " ";
  }
  std::cout << "] ";
  std::cout << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<int>{2, 1, 5, 6, 2, 3});
  solve(std::vector<int>{5, 3, 2, 1, 1, 1, 1});
  solve(std::vector<int>{0});
  solve(std::vector<int>{1});
  solve(std::vector<int>{2, 2, 2, 1});
  solve(std::vector<int>{2, 0, 2});
  solve(std::vector<int>{2, 1, 2});
  return 0;
}
