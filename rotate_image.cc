#include <iostream>
#include <vector>

namespace {

class Solution {
 public:
  void transpose(std::vector<std::vector<int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        std::swap(a[i][j], a[j][i]);
      }
    }
  }

  void reflect(std::vector<std::vector<int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        std::swap(a[i][j], a[i][n - j - 1]);
      }
    }
  }

  void rotate(std::vector<std::vector<int>>& matrix) {
    transpose(matrix);
    reflect(matrix);
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
  sol.rotate(s);
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
  solve(std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  solve(std::vector<std::vector<int>>{
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});
  return 0;
}
