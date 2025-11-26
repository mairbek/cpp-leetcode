#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace {
// https://leetcode.com/problems/word-break-ii/
// DP O(N * M) + backtrack DFS
class Solution {
 public:
  std::vector<std::string> wordBreak(std::string s,
                                     std::vector<std::string>& words) {
    if (s.empty() || words.empty()) {
      return std::vector<std::string>{};
    }
    int n = s.length();
    int m = words.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1));
    dp[0][0] = 1;

    for (int wi = 1; wi <= m; wi++) {
      dp[0][wi] = 0;
    }
    for (int i = 0; i < n; i++) {
      dp[i + 1][0] = 0;
      for (int wi = 0; wi < words.size(); wi++) {
        dp[i + 1][wi + 1] = 0;
        std::string_view word = words[wi];
        int m = word.length();
        if (i < (m - 1)) {
          continue;
        }
        bool match = true;
        for (int j = 0; j < m; j++) {
          if (s[i - m + 1 + j] != word[j]) {
            match = false;
            break;
          }
        }
        if (match && dp[i - m + 1][0]) {
          dp[i + 1][wi + 1] = 1;
          dp[i + 1][0] = 1;
        }
      }
    }
    // Back track with DFS
    std::vector<std::vector<std::pair<int, int>>> st;
    std::vector<std::string> result;
    if (dp[n][0]) {
      for (int wi = 0; wi < m; wi++) {
        if (dp[n][wi + 1]) {
          std::vector<std::pair<int, int>> v;
          v.push_back({n, wi + 1});
          st.push_back(v);
        }
      }
    }
    while (!st.empty()) {
      auto v = st.back();
      st.pop_back();
      auto p = v.back();
      int i = p.first;
      int wi = p.second;
      int d = words[wi - 1].length();
      if (i <= d) {
        std::string s;
        for (int k = v.size() - 1; k >= 0; k--) {
          s += words[v[k].second - 1];
          if (k > 0) {
            s += " ";
          }
        }
        result.push_back(s);
      } else {
        for (int wj = 1; wj <= words.size(); wj++) {
          if (dp[i - d][wj]) {
            std::vector<std::pair<int, int>> newv = v;
            newv.push_back({i - d, wj});
            st.push_back(newv);
          }
        }
      }
    }
    return result;
  }
};
}  // namespace

using int64 = long long;

void solve(std::string s, std::vector<std::string> words) {
  Solution sol;
  auto result = sol.wordBreak(s, words);
  std::cout << s << " | ";
  for (int i = 0; i < result.size(); i++) {
    if (i > 0) {
      std::cout << " | ";
    }
    std::cout << result[i];
  }

  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  solve("a", std::vector<std::string>{});
  solve("leetcode", std::vector<std::string>{"leet", "code"});
  solve("applepenapple", std::vector<std::string>{"apple", "pen"});
  solve("catsandog",
        std::vector<std::string>{"cats", "dog", "sand", "and", "cat"});
  solve("catsanddog",
        std::vector<std::string>{"cats", "dog", "sand", "and", "cat"});
  solve("pineapplepenapple",
        std::vector<std::string>{"apple", "pen", "applepen", "pine",
                                 "pineapple"});
  return 0;
}
