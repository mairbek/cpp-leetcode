#include <iostream>
#include <vector>

namespace {

class Solution {
 public:
  bool dfs(std::vector<std::vector<char>>& board, std::string word,
           std::vector<std::vector<bool>>& visited, int w, int i, int j) {
    int n = board.size();
    int m = board[0].size();
    int ws = word.size();
    if (w >= ws) {
      return true;
    }
    if (i < 0 || i >= n || j < 0 || j >= m) {
      return false;
    }
    if (visited[i][j]) {
      return false;
    }
    if (board[i][j] != word[w]) {
      return false;
    }
    visited[i][j] = true;
    if (dfs(board, word, visited, w + 1, i - 1, j)) {
      return true;
    }
    if (dfs(board, word, visited, w + 1, i, j - 1)) {
      return true;
    }
    if (dfs(board, word, visited, w + 1, i + 1, j)) {
      return true;
    }
    if (dfs(board, word, visited, w + 1, i, j + 1)) {
      return true;
    }
    visited[i][j] = false;
    return false;
  }

  bool exist(std::vector<std::vector<char>>& board, std::string word) {
    int n = board.size();
    int m = board[0].size();
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0]) {
          if (dfs(board, word, visited, 0, i, j)) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
}  // namespace

using int64 = long long;

void solve(std::vector<std::vector<char>> board, std::string word) {
  Solution sol;
  bool result = sol.exist(board, word);
  std::cout << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(
      std::vector<std::vector<char>>{
          {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
      "ABCCED");
  solve(
      std::vector<std::vector<char>>{
          {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
      "SEE");
  solve(
      std::vector<std::vector<char>>{
          {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
      "ABCB");
  solve(
      std::vector<std::vector<char>>{
          {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}},
      "KEK");
  solve(std::vector<std::vector<char>>{{'A'}}, "A");
  solve(std::vector<std::vector<char>>{{'A', 'B'}, {'D', 'C'}}, "ABCD");
  solve(
      std::vector<std::vector<char>>{
          {'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}},
      "ABCESEEEFS");
  return 0;
}
