#include <iostream>
#include <vector>

namespace {

// https://leetcode.com/problems/maximal-rectangle/
// O(N**2) solution using a stack
// Similar to `rectangle_histogram.cc`.
class Solution {
public:
  int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    int n = matrix.size();
    int m = n > 0 ? matrix[0].size() : 0;
    std::vector<int> hor(m, 0);
    int max_area = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == '1') {
          hor[j]++;
        } else {
          hor[j] = 0;
        }
      }
      std::cout << std::endl;
      std::vector<int> st;
      for (int j = 0; j < m; j++) {
        while(!st.empty() && hor[st.back()] >= hor[j]) {
          int top = st.back();
          st.pop_back();

          int area = st.empty() ? j * hor[top] : (j - st.back() - 1) * hor[top];
          max_area = std::max(area, max_area);
        }
        st.push_back(j);
      }
      while(!st.empty()) {
        int top = st.back();
        st.pop_back();

        int area = st.empty() ? m * hor[top] : (m - st.back() - 1) * hor[top];
        max_area = std::max(area, max_area);
      }
    }
    return max_area;
  }
};
} // namespace

using int64 = long long;

void solve(std::vector<std::vector<char>> s) {
  Solution sol;
  int result = sol.maximalRectangle(s);
  std::cout << result << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<std::vector<char>>{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}});
  return 0;
}
