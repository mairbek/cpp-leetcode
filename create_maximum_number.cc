#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

// https://leetcode.com/problems/triangle/
// DP O(n*m) time O(n) space.
namespace {
using int64 =  long long;

class Solution {
 public:
  // fuck me,
  // use segment fucking tree????
  // use other DP relation?
  std::vector<int> maxNumber(std::vector<int>& a, std::vector<int>& b, int k) {
    int an = a.size();
    int bn = b.size();

    int64 dp[k + 1][an + 1][bn + 1];
    for (int i = 0; i <= an; i++) {
      for (int j = 0; j <= bn; j++) {
        dp[0][i][j] = 0;
      }
    }

    for (int ik = 1; ik <= k; ik++) {
      dp[ik][0][0] = 0;
      for (int i = 0; i < an; i++) {
        std::cout << dp[ik - 1][i][0] << a[i] << " " << sum_2dig(dp[ik - 1][i][0], a[i]) << std::endl;
        dp[ik][i + 1][0] =
            std::max(dp[ik][i][0], sum_2dig(dp[ik - 1][i][0], a[i]));
      }
      for (int j = 0; j < bn; j++) {
        std::vector<int> candidates;
        dp[ik][0][j + 1] =
            std::max(dp[ik][0][j], sum_2dig(dp[ik - 1][0][j], b[j]));
      }

      for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
          // int64 previ = i >= ik ? dp[ik][i][j + 1] : 0;
          // int64 prevj = j >= ik ? dp[ik][i + 1][j] : 0;

          dp[ik][i + 1][j + 1] =
              std::max({// previ, prevj,
                        dp[ik][i][j + 1], dp[ik][i + 1][j],
                        sum_2dig(dp[ik - 1][i][j], a[i]),
                        sum_2dig(dp[ik - 1][i][j + 1], a[i]),
                        sum_2dig(dp[ik - 1][i][j], b[j]),
                        sum_2dig(dp[ik - 1][i + 1][j], b[j])});
        }
      }
    }

    for (int ik = 0; ik <= k; ik++) {
      std::cout << " === " << ik << std::endl;

      for (int i = 0; i <= an; i++) {
        for (int j = 0; j <= bn; j++) {
          std::cout << dp[ik][i][j] << " ";
        }
        std::cout << std::endl;
      }
    }
    int64 val = dp[k][an][bn];
    std::vector<int> result(k, 0);
    for (int i = 0; i < k; i++) {
      result[k - i - 1] = val % 10;
      val /= 10;
    }    
    return result;
  }
  int64 sum_2dig(int64 a, int64 b) { return (a)*10 + b; }
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
  // solve(std::vector<int>{8, 6}, std::vector<int>{9, 1, 7}, 5);
  // solve(std::vector<int>{1, 3}, std::vector<int>{2, 4}, 2);
  // solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 2);
  // solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 3);
  solve(std::vector<int>{3, 4, 6, 5}, std::vector<int>{9, 1, 2, 5, 8, 3}, 5);

  // solve(std::vector<int>{6, 7}, std::vector<int>{6, 0, 4}, 5);
  // solve(std::vector<int>{3, 9}, std::vector<int>{8, 9}, 3);
  // solve(std::vector<int>{8,5,9,5,1,6,9}, std::vector<int>{2,6,4,3,8,4,1,0,7,2,9,2,8}, 20);
  return 0;
}
