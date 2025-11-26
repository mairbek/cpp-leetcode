#include <iostream>
#include <vector>

namespace {

class Solution {
 public:
  int floorMod(int x, int y) { return ((x % y) + y) % y; }

  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<int> result;
    int i = 0;
    int j = 0;
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0;
    while (result.size() < n * m) {
      result.push_back(matrix[i][j]);
      visited[i][j] = true;
      int ii = floorMod(i + dir[d][0], n);
      int jj = floorMod(j + dir[d][1], m);
      if (visited[ii][jj]) {
        d = (d + 1) % 4;
      }
      i += dir[d][0];
      j += dir[d][1];
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

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
  solve(std::vector<std::vector<int>>{
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}});
  return 0;
}
