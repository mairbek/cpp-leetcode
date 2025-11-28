#include <iostream>
#include <vector>

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Given an n x n matrix where each of the rows and columns is sorted in
// ascending order, return the kth smallest element in the matrix.
//
// Example 1:
// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15],
//              and the 8th smallest number is 13
//
// Example 2:
// Input: matrix = [[-5]], k = 1
// Output: -5

namespace {

class Solution {
 public:
    int countLessThan(std::vector<std::vector<int>>& matrix, int mid) {
        int count = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] > mid) {
                    break;
                }
                count++;
            }
        }

        return count;
    }

  int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
    // TODO: Implement solution
    int n = matrix.size();
    int m = matrix[0].size();

    int left = matrix[0][0];
    int right = matrix[n - 1][m - 1];
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (countLessThan(matrix, mid) < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
  }
};

}  // namespace

void solve(std::vector<std::vector<int>> matrix, int k, int expected) {
  Solution sol;
  int result = sol.kthSmallest(matrix, k);

  std::cout << "k=" << k << ", result=" << result << ", expected=" << expected
            << (result == expected ? " ✓" : " ✗") << std::endl;
}

int main(int argc, char const** argv) {
  // Example 1
  {
    std::vector<std::vector<int>> matrix = {
        {1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    solve(matrix, 8, 13);
  }

  // Example 2
  {
    std::vector<std::vector<int>> matrix = {{-5}};
    solve(matrix, 1, -5);
  }

  // Additional test cases
  {
    std::vector<std::vector<int>> matrix = {{1, 2}, {1, 3}};
    solve(matrix, 2, 1);
  }

  {
    std::vector<std::vector<int>> matrix = {
        {1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    solve(matrix, 1, 1);
    solve(matrix, 9, 15);
  }

  return 0;
}
