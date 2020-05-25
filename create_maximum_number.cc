#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/triangle/
// DP O(n*m) time O(n) space.
namespace {
struct Node {
  int val;
  Node* prev;

  Node(int val, Node* prev) : val(val), prev(prev) {}
  Node(int val) : val(val), prev(nullptr) {}

  int cmp(const Node& other) const {
    int result = 0;
    const Node* a = this;
    const Node* b = &other;
    while (a != nullptr && b != nullptr) {
      if (a->val == b->val) {
      } else {
        result = a->val < b->val ? -1 : 1;
      }
      a = a->prev;
      b = b->prev;
    }
    return result;
  }
};

class Solution {
 public:
  // fuck me,
  // use segment fucking tree????
  // use other DP relation?

  Node* find_max(std::initializer_list<Node*> nodes) {
    auto it = nodes.begin();
    Node* result = *it;
    for (; it != nodes.end(); ++it) {
      if (result->cmp(**it) < 0) {
        result = *it;
      }
    }
    return result;
  }

  std::string to_string(Node* node) {
    std::string result;
    while (node != nullptr && node->val >= 0) {
      result += std::to_string(node->val);
      node = node->prev;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }

  std::vector<int> maxNumber(std::vector<int>& a, std::vector<int>& b, int k) {
    int an = a.size();
    int bn = b.size();

    Node* root = new Node(-1);

    Node* ndp[k + 1][an + 1][bn + 1];
    for (int i = 0; i <= an; i++) {
      for (int j = 0; j <= bn; j++) {
        ndp[0][i][j] = root;
      }
    }

    for (int ik = 1; ik <= k; ik++) {
      ndp[ik][0][0] = root;
      for (int i = 0; i < an; i++) {
        ndp[ik][i + 1][0] =
            find_max({ndp[ik][i][0], new Node(a[i], ndp[ik - 1][i][0])});
      }
      for (int j = 0; j < bn; j++) {
        ndp[ik][0][j + 1] =
            find_max({ndp[ik][0][j], new Node(b[j], ndp[ik - 1][0][j])});
      }

      for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
          // int64 previ = i >= ik ? dp[ik][i][j + 1] : 0;
          // int64 prevj = j >= ik ? dp[ik][i + 1][j] : 0;
          ndp[ik][i + 1][j + 1] =
              find_max({// previ, prevj,
                        ndp[ik][i][j + 1], ndp[ik][i + 1][j],
                        new Node(a[i], ndp[ik - 1][i][j]),
                        new Node(a[i], ndp[ik - 1][i][j + 1]),
                        new Node(b[j], ndp[ik - 1][i][j]),
                        new Node(b[j], ndp[ik - 1][i + 1][j])});
        }
      }
    }
    Node* node = ndp[k][an][bn];
    std::vector<int> result(k, 0);
    for (int i = 0; i < k; i++) {
      result[k - i - 1] = node->val;
      node = node->prev;
    }

    return result;
  }
};
}  // namespace

void solve(std::vector<int> a, std::vector<int> b, int k) {
  Solution sol;
  // sol.max_num(a, k);
  // sol.max_num(b, k);
  auto result = sol.maxNumber(a, b, k);
  std::cout << k << " | [";
  for (int i = 0; i < a.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << a[i];
  }
  std::cout << "] | [";
  for (int i = 0; i < b.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << b[i];
  }
  std::cout << "] | [";
  for (int i = 0; i < result.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << result[i];
  }
  std::cout << "]" << std::endl;
}

int main(int argc, const char** argv) {
  // Node a(3, new Node(4));
  // Node b(2, new Node(4));
  // std::cout << b.cmp(a) << std::endl;
  // solve(std::vector<int>{8, 6}, std::vector<int>{9, 1, 7}, 5);
  solve(std::vector<int>{1, 3}, std::vector<int>{2, 4}, 2);
  // solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 2);
  // solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 3);
  // solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 5);

  // solve(std::vector<int>{6, 7}, std::vector<int>{6, 0, 4}, 5);
  // solve(std::vector<int>{3, 9}, std::vector<int>{8, 9}, 3);
  // solve(std::vector<int>{8,5,9,5,1,6,9},
  // std::vector<int>{2,6,4,3,8,4,1,0,7,2,9,2,8}, 20);
  solve(std::vector<int>{1, 5, 8, 1, 4, 0, 8, 5, 0, 7, 0, 5, 7, 6, 0, 5,
                         5, 2, 4, 3, 6, 4, 6, 6, 3, 8, 1, 1, 3, 1, 3, 5,
                         4, 3, 9, 5, 0, 3, 8, 1, 4, 9, 8, 8, 3, 4, 6, 2,
                         5, 4, 1, 1, 4, 6, 5, 2, 3, 6, 3, 5, 4, 3, 0, 7,
                         2, 5, 1, 5, 3, 3, 8, 2, 2, 7, 6, 7, 5, 9, 1, 2},
        std::vector<int>{7, 8, 5, 8, 0, 1, 1, 6, 1, 7, 6, 9, 6, 6, 0, 8,
                         5, 8, 6, 3, 4, 0, 4, 6, 7, 8, 7, 7, 7, 5, 7, 2,
                         5, 2, 1, 9, 5, 9, 3, 7, 3, 9, 9, 3, 1, 4, 3, 3,
                         9, 7, 1, 4, 4, 1, 4, 0, 2, 3, 1, 3, 2, 0, 2, 4,
                         0, 9, 2, 0, 1, 3, 9, 1, 2, 2, 6, 6, 9, 3, 6, 0},
        80);
  return 0;
}
