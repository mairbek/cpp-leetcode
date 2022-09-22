#include <climits>
#include <iostream>
#include <vector>

namespace {

class Solution {
 public:
  int traverse(std::vector<std::vector<int>>& matrix, std::vector<int>* result, std::vector<std::vector<bool>>* visited, int* i, int* j, int di, int dj) {
      int count = 0;
      int n = matrix.size();
      int m = matrix[0].size();
      while (true) {
        int ii = *i + di;
        int jj = *j + dj;
        if (ii >= n) {
            break;
        }
        if (jj >= m) {
            break;
        }
        if (ii < 0) {
            break;
        }
        if (jj < 0) {
            break;
        }
        if ((*visited)[ii][jj]) {
            break;
        }
        result->push_back(matrix[ii][jj]);
        (*visited)[ii][jj] = true;
        *i = ii;
        *j = jj;
        count++;
      }
      return count;
  }

  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;
    int j = -1;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    while (result.size() < n * m) {
        if (traverse(matrix, &result, &visited, &i, &j, 0, 1) == 0) {
            break;
        }
        if (traverse(matrix, &result, &visited, &i, &j, 1, 0) == 0) {
            break;
        }
        if (traverse(matrix, &result, &visited, &i, &j, 0, -1) == 0) {
            break;
        }
        if (traverse(matrix, &result, &visited, &i, &j, -1, 0) == 0) {
            break;
        }
    }
    return result;
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
  std::cout << "] | ";
  auto result = sol.spiralOrder(s);
  std::cout << "[";
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, const char** argv) {
  solve(std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  solve(std::vector<std::vector<int>>{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});
  return 0;
}
