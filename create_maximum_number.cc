#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/create-maximum-number/
// DP O(n*k) preproc, O(k**2) solution, time O(nk) space.
// fking struggle.
namespace {

using Matrix = std::vector<std::vector<int>>;

class Solution {
 public:
  Matrix build_vecs(std::vector<int>& a, int k) {
    Matrix result;
    int an = a.size();
    int ak = std::min(k, an);

    result.push_back(std::vector<int>(an, 0));
    for (int ik = 0; ik < ak; ik++) {
      result.push_back(std::vector<int>(an - ik));
      int prev = -1;
      int idx = -1;
      for (int i = an - ik - 1; i >= 0; i--) {
        if (idx == -1 || a[i] >= prev) {
          idx = i;
          prev = a[i];
        }
        result[ik][i] = idx;
      }
    }
    return result;
  }

  std::vector<int> vecof(Matrix& m, std::vector<int>& a, int k) {
    std::vector<int> result;
    int i = 0;
    for (int ik = k - 1; ik >= 0; ik--) {
      int idx = m[ik][i];
      result.push_back(a[idx]);
      i = idx + 1;
    }
    return result;
  }

  std::vector<int> merge(std::vector<int>& a, std::vector<int>& b) {
    std::vector<int> result;
    int ai = 0;
    int bi = 0;
    while (ai < a.size() || bi < b.size()) {
      if (ai >= a.size()) {
        result.push_back(b[bi++]);
        continue;
      }
      if (bi >= b.size()) {
        result.push_back(a[ai++]);
        continue;
      }
      if (lookahead_gt(a, b, ai, bi)) {
        result.push_back(a[ai++]);
      } else {
        result.push_back(b[bi++]);
      }
    }
    return result;
  }

  bool lookahead_gt(std::vector<int>& a, std::vector<int>& b, int ai, int bi) {
    while (ai < a.size() && bi < b.size()) {
      if (a[ai] != b[bi]) {
        break;
      }
      ai++;
      bi++;
    }
    if (ai < a.size() && bi < b.size()) {
      return a[ai] > b[bi];
    }
    return bi >= b.size();
  }

  bool gt(std::vector<int>& a, std::vector<int>& b) {
    for (int i = 0; i < a.size(); i++) {
      if (a[i] > b[i]) {
        return true;
      }
      if (a[i] < b[i]) {
        return false;
      }
    }
    return false;
  }

  std::vector<int> maxNumber(std::vector<int>& a, std::vector<int>& b, int k) {
    Matrix am = build_vecs(a, k);
    Matrix mb = build_vecs(b, k);
    int an = a.size();
    int bn = b.size();

    std::vector<int> result;
    for (int ak = 0; ak <= std::min(k, an); ak++) {
      int bk = k - ak;

      if (bk > bn) {
        continue;
      }

      std::vector<int> av = vecof(am, a, ak);
      std::vector<int> bv = vecof(mb, b, bk);
      std::vector<int> rr = merge(av, bv);

      if (result.empty() || gt(rr, result)) {
        result = rr;
      }
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
  solve(std::vector<int>{8, 6}, std::vector<int>{9, 1, 7}, 5);
  solve(std::vector<int>{1, 3}, std::vector<int>{2, 4}, 2);
  solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 2);
  solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 3);
  solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 5);

  solve(std::vector<int>{6, 7}, std::vector<int>{6, 0, 4}, 5);
  solve(std::vector<int>{6, 6, 7}, std::vector<int>{6, 0, 4}, 6);
  solve(std::vector<int>{6, 7}, std::vector<int>{6, 6, 0, 4}, 6);
  solve(std::vector<int>{3, 9}, std::vector<int>{8, 9}, 3);
  solve(std::vector<int>{8, 6, 9}, std::vector<int>{1, 7, 5}, 3);
  solve(std::vector<int>{8, 5, 9, 5, 1, 6, 9},
        std::vector<int>{2, 6, 4, 3, 8, 4, 1, 0, 7, 2, 9, 2, 8}, 20);
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

  solve(std::vector<int>{6, 3, 9, 0, 5, 6},
        std::vector<int>{2, 2, 5, 2, 1, 4, 4, 5, 7, 8, 9, 3, 1, 6, 9, 7, 0},
        23);

  return 0;
}
