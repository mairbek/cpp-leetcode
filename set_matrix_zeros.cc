#include <iostream>
#include <vector>

namespace {

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<bool> ns(n, false);
    std::vector<bool> ms(m, false);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          ns[i] = true;
          ms[j] = true;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ns[i] || ms[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> s) {
  Solution sol;
  std::cout << "[" << std::endl;
  for (int i = 0; i < s.size(); i++) {
    std::cout << "\t[";
    for (int j = 0; j < s[i].size(); j++) {
      std::cout << s[i][j] << " ";
    }
    std::cout << "]," << std::endl;
  }
  std::cout << "] ";
  sol.setZeroes(s);
  std::cout << "[" << std::endl;
  for (int i = 0; i < s.size(); i++) {
    std::cout << "\t[";
    for (int j = 0; j < s[i].size(); j++) {
      std::cout << s[i][j] << " ";
    }
    std::cout << "]," << std::endl;
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}});
  solve(
      std::vector<std::vector<int>>{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}});
  return 0;
}
