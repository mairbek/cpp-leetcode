#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int l = 0;
    int r = n * m;

    while (l != r) {
      int mid = (l + r) / 2;
      int i = mid / m;
      int j = mid - i * m;
      /*
      std::cout << "l=" << l << " r=" << r << " "
                << "i=" << i << " j=" << j << " m[i][j]=" << matrix[i][j]
                << std::endl;
      */
      if (target == matrix[i][j]) {
        return true;
      }
      if (target > matrix[i][j]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return false;
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> matrix, int target) {
  Solution sol;
  auto result = sol.searchMatrix(matrix, target);

  std::cout << (result ? "T" : "F") << std::endl;
}

int main(int argc, char const** argv) {
  solve(
      std::vector<std::vector<int>>{
          {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}},
      3);
  solve(
      std::vector<std::vector<int>>{
          {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}},
      13);
  return 0;
}
